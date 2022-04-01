/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:13:28 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:28 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*flex_s1;
	unsigned char	*flex_s2;

	flex_s1 = (unsigned char *)s1;
	flex_s2 = (unsigned char *)s2;
	i = 0;
	while (i != n)
	{
		if (flex_s1[i] != flex_s2[i])
			return (flex_s1[i] - flex_s2[i]);
		i++;
	}
	return (0);
}
