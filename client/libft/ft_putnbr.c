/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:53:22 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:03:05 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int i;
	int k;

	i = 0;
	k = -1;
	if (nb == -2147483648)
	{
		ft_putchar(45);
		ft_putchar(50);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar(45);
		return (ft_putnbr(nb * k));
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}
