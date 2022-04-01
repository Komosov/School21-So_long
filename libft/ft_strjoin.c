/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:46:55 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/17 13:59:37 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (ft_strlen((char *)s1)))
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen((char *)s1) + ft_strlen((char *)s2)))
	{
		res[i] = s2[i - ft_strlen((char *)s1)];
		i++;
	}
	res[i] = '\0';
	return (res);
}
