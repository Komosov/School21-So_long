/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:07:17 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:17:10 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	int		i;
	size_t	dst_sz;
	size_t	res;

	dst_sz = ft_strlen(dst);
	if (size > dst_sz)
		res = ft_strlen((char *)src) + dst_sz;
	else
		res = ft_strlen((char *)src) + size;
	i = 0;
	while (src[i] && ((dst_sz + 1) < size))
	{
		dst[dst_sz] = src[i];
		dst_sz++;
		i++;
	}
	if (size > dst_sz)
		dst[dst_sz] = '\0';
	return (res);
}
