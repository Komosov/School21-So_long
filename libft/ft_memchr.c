/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:54:38 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:23 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				found;
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)s;
	found = 0;
	i = 0;
	while ((found != 1) && (i != n))
	{
		if (arr[i] == (unsigned char)c)
			found = 1;
		i++;
	}
	if (1 == found)
		return (arr + i - 1);
	return (NULL);
}
