/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:36:55 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:38 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*flex_dst;
	char	*flex_src;
	size_t	i;

	if ((!(dst || src)) || (len == 0))
		return (dst);
	flex_dst = (char *)dst;
	flex_src = (char *)src;
	if (flex_dst < flex_src)
	{
		i = 0;
		while (i != len)
		{
			flex_dst[i] = flex_src[i];
			i++;
		}
		return (flex_dst);
	}
	i = len;
	while (i != 0)
	{
		flex_dst[i - 1] = flex_src[i - 1];
		i--;
	}
	return (flex_dst);
}
