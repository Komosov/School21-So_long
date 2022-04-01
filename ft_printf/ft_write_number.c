/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:29:46 by lhelena           #+#    #+#             */
/*   Updated: 2022/01/11 19:49:39 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_number(char *str, unsigned long l, unsigned long base, int *ret)
{
	if (l < base)
	{
		write(1, &str[l], 1);
		*ret += 1;
	}
	else
	{
		write_number(str, l / base, base, ret);
		write_number(str, l % base, base, ret);
	}
}

void	write_number_x(char *str, unsigned int l, unsigned int base, int *ret)
{
	if (l < base)
	{
		write(1, &str[l], 1);
		*ret += 1;
	}
	else
	{
		write_number(str, l / base, base, ret);
		write_number(str, l % base, base, ret);
	}
}
