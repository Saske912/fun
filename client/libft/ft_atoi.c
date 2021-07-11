/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:46:00 by pfile             #+#    #+#             */
/*   Updated: 2020/05/18 09:46:39 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int		k;
	int		nb;

	nb = 0;
	k = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		++str;
	if (*str == 43 || *str == 45)
		if (*str++ == 45)
			k = -1;
	while (ft_isdigit(*str))
		nb = nb * 10 + (*str++ - 48);
	return (nb * k);
}
