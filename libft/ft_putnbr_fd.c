/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:29:38 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:20:55 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)

{
	unsigned int	unsgn_n;

	if (n < 0)
		write (fd, "-", 1);
	if (n < 0)
		unsgn_n = -(unsigned int)n;
	else
		unsgn_n = (unsigned int)n;
	if (unsgn_n >= 10)
		ft_putnbr_fd(unsgn_n / 10, fd);
	ft_putchar_fd((char)(unsgn_n % 10 + 48), fd);
}
