/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:13:13 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:21:41 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (NULL);
	count = ft_strlen(s);
	if (start <= count)
		count = ft_strlen(s) - start;
	if (len < count)
		count = len;
	res = (char *)ft_calloc(sizeof(char) * (count + 1), 1);
	if (!res)
		return (NULL);
	if (start > ((unsigned int)ft_strlen(s) - 1))
		return (res);
	i = 0;
	while (i < count)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
