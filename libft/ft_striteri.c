/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:24:34 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:21:19 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (a == 0)
	{
		if (!s || !f)
			break ;
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
		a++;
	}
}
