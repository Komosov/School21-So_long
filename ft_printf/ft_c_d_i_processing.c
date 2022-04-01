/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_d_i_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:35:07 by lhelena           #+#    #+#             */
/*   Updated: 2022/01/11 19:53:05 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_d_i_processing(char *p_ptr, long lval, int *p_ret)
{
	if (*p_ptr == 'c')
		c_processing(lval, p_ret);
	else if ((*p_ptr == 'd') || (*p_ptr == 'i'))
		d_i_processing(lval, p_ret);
}

void	c_processing(char cval, int *p_ret)
{
	write(1, &cval, 1);
	*p_ret += 1;
}

void	d_i_processing(long lval, int *p_ret)
{
	if (lval < 0)
	{
		write(1, "-", 1);
		*p_ret += 1;
		lval = -lval;
	}
	write_number("0123456789", lval, 10, p_ret);
}
