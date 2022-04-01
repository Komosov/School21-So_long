/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:01:45 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/16 14:29:49 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
void	ft_putstr_fd_pf(char *s, int fd);
size_t	ft_strlen_pf(const char *s);
void	write_number(char *str, unsigned long l, unsigned long base, int *ret);
void	write_number_x(char *str, unsigned int l, unsigned int base, int *ret);
void	c_d_i_processing(char *p_ptr, long lval, int *p_ret);
void	c_processing(char cval, int *p_ret);
void	d_i_processing(long lval, int *p_ret);
void	s_processing(char *sval, int *p_ret);
void	u_processing(unsigned int uival, int *p_ret);
void	p_processing(unsigned long ptr, int *p_ret);

#endif
