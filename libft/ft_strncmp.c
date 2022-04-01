/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:14 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:17:23 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*flex_s1;
	unsigned char	*flex_s2;
	size_t			i;

	i = 0;
	flex_s1 = (unsigned char *)s1;
	flex_s2 = (unsigned char *)s2;
	while (flex_s1[i] && flex_s2[i] && n != i && flex_s1[i] == flex_s2[i])
		i++;
	if (i == n)
		return (0);
	return (flex_s1[i] - flex_s2[i]);
}
