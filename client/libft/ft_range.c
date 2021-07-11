/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:58:31 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 11:58:41 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *ints;
	int count;

	if (min == max || min > max)
		return (0);
	ints = malloc(sizeof(int) * (max - min) + 1);
	count = -1;
	min = min - 1;
	while (++min < max)
		ints[++count] = min;
	ints[++count] = '\0';
	return (ints);
}
