/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:54:41 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:17:45 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int k;

	i = -1;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[k])
		{
			while (to_find[++k] != '\0')
			{
				if (to_find[k] != str[i + k])
					break ;
			}
			if (to_find[k] == '\0')
				return (&str[i]);
			k = 0;
		}
	}
	return ("\0");
}
