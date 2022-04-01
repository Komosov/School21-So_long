/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:09:36 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:17:43 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	real_c;
	char	*flex_s;

	real_c = (char)c;
	flex_s = (char *)s;
	size = ft_strlen(flex_s);
	while ((s[size] != real_c) && (size != 0))
		size--;
	if (s[size] == real_c)
		return (&flex_s[size]);
	return (NULL);
}
