/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 07:24:18 by pfile             #+#    #+#             */
/*   Updated: 2020/06/08 07:25:32 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;

	if (min == max || min > max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min + 1));
	count = -1;
	min = min - 1;
	while (++min < max)
		range[0][++count] = min;
	range[0][++count] = '\0';
	return (count);
}
