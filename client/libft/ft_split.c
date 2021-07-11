/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:54:18 by pfile             #+#    #+#             */
/*   Updated: 2020/05/20 08:57:41 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_space(char z, char c)
{
	return (z == c || z == '\0');
}

static char	*paste(char **str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (!free_space((*str)[i], c))
		i++;
	if (!(word = (char *)ft_calloc(i + 1, sizeof(char))))
		return (0);
	ft_strlcpy(word, *str, i + 1);
	*str = *str + i;
	return (word);
}

static void	*free1(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (0);
}

static char	**do_split(const char *s, char c)
{
	char	**strings;
	size_t	coun;
	size_t	k;

	k = 0;
	coun = !free_space(s[0], c);
	while (++k && s[k])
		coun += free_space(s[k - 1], c) && !free_space(s[k], c);
	if (!(strings = (char **)ft_calloc((coun + 1), sizeof(char *))))
		return (0);
	return (strings);
}

char		**ft_split(char const *s, char c)
{
	char	**strings;
	int		word;

	if (!s)
		return (0);
	if (!(strings = do_split(s, c)))
		return (0);
	word = 0;
	while (*s)
	{
		if (!free_space(*s, c))
		{
			if (!(strings[word++] = paste((char **)&s, c)))
				return (free1(strings));
		}
		else
			s++;
	}
	return (strings);
}
