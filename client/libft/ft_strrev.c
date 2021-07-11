/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:55:11 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:17:14 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	l;
	int		k;
	int		count;

	k = -1;
	while (str[++k] != '\0')
		continue;
	count = -1;
	while (++count != --k && count < k)
	{
		l = str[count];
		str[count] = str[k];
		str[k] = l;
	}
	return (str);
}
