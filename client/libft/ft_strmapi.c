/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:51:36 by pfile             #+#    #+#             */
/*   Updated: 2020/05/09 18:27:02 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*back_str;

	if (!s || !f)
		return (0);
	if (!(back_str = (char *)malloc((ft_strlen((char *)s)\
						+ 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < ft_strlen((char *)s))
		back_str[i] = f(i, s[i]);
	back_str[i] = '\0';
	return (back_str);
}
