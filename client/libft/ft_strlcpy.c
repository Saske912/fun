/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:13:16 by pfile             #+#    #+#             */
/*   Updated: 2020/05/18 10:56:59 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dst)
		return (0);
	else if (dstsize)
	{
		dstsize = dstsize <= ft_strlen(src) ? dstsize - 1 : ft_strlen(src);
		ft_memcpy(dst, src, dstsize);
		dst[dstsize] = '\0';
	}
	return (ft_strlen(src));
}
