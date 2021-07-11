/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:34:31 by pfile             #+#    #+#             */
/*   Updated: 2020/05/18 08:11:21 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*perfect_string;

	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	len = (ft_strlen(s) - start < len ? ft_strlen(s) - start : len);
	if (!(perfect_string = (char *)malloc((++len) * sizeof(char))))
		return (0);
	ft_strlcpy(perfect_string, s + start, len);
	return (perfect_string);
}
