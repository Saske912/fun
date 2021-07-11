/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:56:01 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 11:59:43 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	else
		while (i < nb / i)
		{
			if (nb % i == 0)
				return (ft_find_next_prime(nb + 1));
			i++;
		}
	return (nb);
}
