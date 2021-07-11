/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:13:47 by pfile             #+#    #+#             */
/*   Updated: 2020/05/09 17:30:58 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	min_number(int *nb, int *min)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*min = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		min;
	int		number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = n;
	min = 0;
	i = 2;
	min_number(&n, &min);
	while (number /= 10)
		i++;
	i += min;
	if (!(string = (char *)malloc(i * sizeof(char))))
		return (0);
	string[--i] = '\0';
	while (i--)
	{
		string[i] = n % 10 + 48;
		n = n / 10;
	}
	if (min)
		string[0] = 45;
	return (string);
}
