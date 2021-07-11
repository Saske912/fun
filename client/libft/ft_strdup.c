/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:36:46 by pfile             #+#    #+#             */
/*   Updated: 2020/05/18 07:41:57 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*src1;

	if (!(src1 = (char *)malloc((1 + ft_strlen(src)) * sizeof(char))))
		return (0);
	ft_strlcpy(src1, src, ft_strlen(src) + 1);
	return (src1);
}
