/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:39:33 by pfile             #+#    #+#             */
/*   Updated: 2020/05/05 21:16:12 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count1;
	size_t	count2;
	char	*hay;

	hay = (char *)haystack;
	if (needle[0] == '\0')
		return (hay);
	if (!len)
		return (0);
	count1 = -1;
	while (*hay && ++count1 < len)
	{
		count2 = 0;
		while (needle[count2] && hay[count2] == needle[count2])
			if (++count2 + count1 > len)
				return (0);
		if (count2 == ft_strlen((char *)needle) || !needle[count2])
			return (hay);
		hay++;
	}
	return (0);
}
