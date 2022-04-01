/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:23:02 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:33 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*flex_dst;
	char	*flex_src;

	if (!(dst || src))
		return (dst);
	i = 0;
	flex_dst = (char *)dst;
	flex_src = (char *)src;
	while (i != n)
	{
		flex_dst[i] = flex_src[i];
		i++;
	}
	return (flex_dst);
}
