/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:58:09 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:26:08 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char **av)
{
	int		count;

	count = 1;
	while (*av)
		count += ft_strlen(*av++);
	return (count);
}

char		*ft_concat_params(int argc, char **argv)
{
	char	*string;
	int		i;
	int		k;
	int		count;

	if (!argc)
		return (0);
	if (!(string = (char *)malloc(sizeof(char) * len(argv))))
		return (0);
	i = -1;
	count = -1;
	while (argv[++i] != '\0')
	{
		while (argv[i][++k] != '\0')
			string[++count] = argv[i][k];
		k = -1;
		string[++count] = '\n';
	}
	string[++count] = '\0';
	return (string);
}
