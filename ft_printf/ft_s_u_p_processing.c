/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_u_p_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:15 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/16 14:31:39 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_processing(char *sval, int *p_ret)
{
	if (sval == NULL)
	{
		write(1, "(null)", 6);
		*p_ret += 6;
	}
	else
	{
		ft_putstr_fd_pf(sval, 1);
		*p_ret += ft_strlen_pf(sval);
	}
}

void	u_processing(unsigned int uival, int *p_ret)
{
	write_number("0123456789", uival, 10, p_ret);
}

void	p_processing(unsigned long ptr, int *p_ret)
{
	write(1, "0x", 2);
	*p_ret += 2;
	write_number("0123456789abcdef", ptr, 16, p_ret);
}
