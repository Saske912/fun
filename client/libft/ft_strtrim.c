/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:29:23 by pfile             #+#    #+#             */
/*   Updated: 2020/05/07 18:52:15 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contain(char a, char const *set)
{
	int	c;

	c = -1;
	while (set[++c])
		if (set[c] == a)
			return (1);
	return (0);
}

static int	len_tr(char const *s1, char const *set)
{
	int	a;
	int b;

	a = -1;
	b = 0;
	while (contain(s1[++a], set))
		b++;
	if (a < (int)ft_strlen(s1))
	{
		while (s1[a])
			a++;
		while (contain(s1[--a], set))
			b++;
	}
	return (ft_strlen((char *)s1) - b);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		v;
	int		count;

	if (!set || !s1)
		return ((char *)s1);
	trim = (char *)malloc((len_tr(s1, set) + 1) * sizeof(char));
	if (!trim)
		return (0);
	v = 0;
	count = -1;
	while (contain(s1[v], set))
		v++;
	while (++count < len_tr(s1, set))
		trim[count] = s1[v + count];
	trim[count] = '\0';
	return (trim);
}
