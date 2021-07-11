/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:55:44 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 11:55:46 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1 && nb <= 13)
		return (nb * ft_recursive_factorial(nb - 1));
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 13)
		return (0);
	return (nb);
}
