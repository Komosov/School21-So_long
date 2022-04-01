/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:04:02 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:53 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	real_c;
	char	*flex_s;

	real_c = (char)c;
	flex_s = (char *)s;
	i = 0;
	while (flex_s[i] && flex_s[i] != real_c)
		i++;
	if ((flex_s[i] == '\0') && real_c)
		return (NULL);
	return (&flex_s[i]);
}
