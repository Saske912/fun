/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:24:04 by pfile             #+#    #+#             */
/*   Updated: 2020/05/18 12:25:42 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*counter;

	if (!ft_strchr(s, c))
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while ((counter = ft_strchr(s, c)))
		s += ft_strlen(s) - ft_strlen(counter) + 1;
	return ((char *)--s);
}
