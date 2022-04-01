/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:01:21 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/26 11:46:55 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*find_percent(char *find_ptr, int *p_ret)
{
	while ((*find_ptr != '%') && (*find_ptr))
	{
		write(1, find_ptr, 1);
		find_ptr++;
		*p_ret += 1;
	}
	if (*find_ptr == '%')
		find_ptr++;
	return (find_ptr);
}

void	not_null_processing(char cval, int *p_ret)
{
	write(1, &cval, 1);
	*p_ret += 1;
}

void	p_x_processing(char *p_ptr, unsigned long l, int *p_ret)
{
	if (*p_ptr == 'p')
		p_processing(l, p_ret);
	else if (*p_ptr == 'x')
		write_number_x("0123456789abcdef", l, 16, p_ret);
	else if (*p_ptr == 'X')
		write_number_x("0123456789ABCDEF", l, 16, p_ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ptr;
	int		ret;

	ret = 0;
	ptr = (char *)fmt;
	va_start(ap, fmt);
	while (*ptr)
	{
		ptr = find_percent(ptr, &ret);
		if ((*ptr == 'c') || (*ptr == 'd') || (*ptr == 'i'))
			c_d_i_processing(ptr, (va_arg(ap, int)), &ret);
		else if (*ptr == 's')
			s_processing((va_arg(ap, char *)), &ret);
		else if ((*ptr == 'p') || (*ptr == 'x') || (*ptr == 'X'))
			p_x_processing(ptr, (va_arg(ap, unsigned long)), &ret);
		else if (*ptr == 'u')
			u_processing((va_arg(ap, unsigned int)), &ret);
		else if (*ptr != '\0')
			not_null_processing(*ptr, &ret);
		if (*ptr != '\0')
			ptr++;
	}
	va_end(ap);
	return (ret);
}
