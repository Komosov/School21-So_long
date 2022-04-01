/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:56:34 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:18 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_power(int nb, int power)
{
	if ((power == 0) || ((nb == 1) && (power < 0)))
		return (1);
	if (power < 0)
		return (0);
	else
		return (nb * ft_recursive_power (nb, power - 1));
}

int	ft_itoa_module(int a)
{
	if (a < 0)
		return (a = -a);
	return (a);
}

int	ft_itoa_minus_num(int a)
{
	if (a < 0)
		return (1);
	return (0);
}

unsigned int	ft_itoa_symbols(int a)
{
	unsigned int	tmp_symbols_num;
	unsigned int	symbols;

	symbols = 1;
	tmp_symbols_num = ft_itoa_module(a);
	while (tmp_symbols_num >= 10)
	{
		tmp_symbols_num /= 10;
		symbols++;
	}
	return (symbols);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	tmp_num;
	unsigned int	digit;
	unsigned int	symbols;
	unsigned int	i;

	tmp_num = ft_itoa_module(n);
	symbols = ft_itoa_symbols(n);
	str = (char *)malloc(sizeof(char) * (symbols + ft_itoa_minus_num(n) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = 0;
	if (n < 0)
		i = 1;
	while (symbols-- != 0)
	{
		digit = tmp_num / ft_recursive_power(10, symbols);
		str[i] = digit + '0';
		tmp_num = tmp_num - digit * ft_recursive_power(10, symbols);
		i++;
	}
	str[i] = '\0';
	return (str);
}
