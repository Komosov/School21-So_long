/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:44:20 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:17:14 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = dstsize;
	while (src[i] && len > 1)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
