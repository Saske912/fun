#include <iostream>
#include <sys/socket.h>
#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <netdb.h>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>

int     host = 0;

typedef struct  client
{
    int     socket;
    struct client *next;
}               t_client;

void error_exit(std::string const & err)
{
    close(host);
    perror(err.c_str());
    exit(1);
}

void check_int_fatal(int ret, std::string msg)
{
    if (ret == -1)
    {
        error_exit("Fatal error " + msg);
    }
}

void check_buf_fatal(void *buf)
{
    if (!buf)
    {
        error_exit("Fatal error\n");
    }
}

t_client *new_lst(int sock)
{
    t_client *ret = new t_client;
    check_buf_fatal(ret);
    ret->socket = sock;
    ret->next = nullptr;
    return ret;
}

void lst_add_back(t_client *head, t_client *new_lst)
{
    while (head->next)
        head = head->next;
    head->next = new_lst;
}

t_client *lst_del_one(t_client *head, t_client *del)
{
    t_client *temp;

    while (head->socket != del->socket)
    {
        temp = head;
        head = head->next;
    }
    temp->next = head->next;
    close(head->socket);
    free(head);
    return temp->next;
}

int sendmail(const char *to, const char *from, const char *subject, const char *message)
{
    int retval = -1;
    FILE *mailpipe = popen("/usr/sbin/sendmail -t", "w");
    if (mailpipe != nullptr) {
        fprintf(mailpipe, "To: %s\n", to);
        fprintf(mailpipe, "From: %s\n", from);
        fprintf(mailpipe, "Subject: %s\n\n", subject);
        fwrite(message, 1, strlen(message), mailpipe);
        fwrite(".\n", 1, 2, mailpipe);
        pclose(mailpipe);
        retval = 0;
    }
    else {
        perror("Failed to invoke sendmail");
    }
    return retval;
}

void loop(t_client *head)
{
    std::string comm;
    fd_set read_set;
    fd_set write_set;
    t_client *temp;
    int max_fd = 0;
    int ret;
    struct timeval tv;
    struct sockaddr_in cli;
    bzero(&cli, sizeof(sockaddr_in));
    socklen_t len = sizeof(sockaddr);
    socklen_t check_len = sizeof(ret);
    char buf[400];

    tv.tv_sec = 3;
    tv.tv_usec = 0;
    while (21)
    {
        FD_ZERO(&read_set);
        FD_ZERO(&write_set);
        temp = head;
        while (temp)
        {
            FD_SET(temp->socket, &read_set);
            if (temp->socket > max_fd)
                max_fd = temp->socket;
            if (head->socket != temp->socket)
                FD_SET(temp->socket, &write_set);
            temp = temp->next;
        }
        ret = select(max_fd + 1, &read_set, &write_set, NULL, &tv);
        check_int_fatal(ret, "select");
        if (!ret)
            continue ;
        else
        {
            if ( FD_ISSET(head->socket, &read_set))
            {
                ret = accept(head->socket, (struct sockaddr *)&cli, &len);
                check_int_fatal(ret, "accept");
                lst_add_back(head, new_lst(ret));
                errno = 0;
                ret = sendmail("predisoin@gmail.com", "pfile@studend.21-school.ru", "new client", "do this!");
                check_int_fatal(ret, "sendmail");
            }
            temp = head->next;
            while (temp)
            {
                getsockopt(temp->socket, SOL_SOCKET, SO_ERROR, &ret, &check_len);
                std::cout << "ret: " << ret  << std::endl;
                if (ret == 54)
                {
                    temp = lst_del_one(head, temp);
                    continue ;
                }
                if ( FD_ISSET(temp->socket, &read_set))
                {
                    bzero(buf, 400);
                    ret = recv(temp->socket, buf, 399, 0);
                    if (!ret)
                    {
                        temp = lst_del_one(head, temp);
                        continue ;
                    }
                    else
                    {
                        std::cout << "message from client: " << buf << std::endl;
                    }
                }
                if ( FD_ISSET(temp->socket, &write_set))
                {
                    std::cout << "enter command: ";
                    std::cin >> comm;
                    ret = send(temp->socket, comm.c_str(), comm.length(), 0);
                    check_int_fatal(ret, "send");
                }
                temp = temp->next;
            }
        }
    }
}

int main(int ac, char **av)
{
    int     ret;
    struct sockaddr_in addr;
    socklen_t len;
    t_client head;
    int val = 1;

    if (ac != 3)
        error_exit("3 args");
    addr.sin_addr.s_addr = inet_addr(av[1]);
    addr.sin_port = htons(atoi(av[2]));
    len = sizeof(addr);
    host = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(host, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    check_int_fatal(host, "socket");
    ret = bind(host, (const sockaddr *)&addr, len);
    check_int_fatal(ret, "bind");
    ret = listen(host, 10);
    check_int_fatal(ret, "listen");
    head.socket = host;
    head.next = NULL;
    loop(&head);
}
