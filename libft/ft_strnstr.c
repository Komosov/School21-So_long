/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:11:21 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/17 14:00:36 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_to_search;
	char	*flex_hey;
	char	*flex_sub;

	flex_hey = (char *)haystack;
	flex_sub = (char *)needle;
	if (!(ft_strlen(flex_sub)))
		return (flex_hey);
	if ((ft_strlen(flex_hey) < ft_strlen(flex_sub)) || (!len))
		return (NULL);
	if (ft_strlen(flex_hey) <= len)
		size_to_search = (ft_strlen(flex_hey) - ft_strlen(flex_sub));
	else
		size_to_search = (len - ft_strlen(flex_sub));
	i = 0;
	while (i <= size_to_search)
	{
		if (ft_strncmp(&flex_hey[i], flex_sub, ft_strlen(flex_sub)) == 0)
			return (&flex_hey[i]);
		i++;
	}
	return (NULL);
}
