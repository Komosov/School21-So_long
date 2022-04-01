/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:31:37 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/13 12:51:34 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	ft_sl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_sl_to_n(const char *s)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	long	i;
	long	s1_len;
	long	s2_len;

	s1_len = ft_sl(s1);
	s2_len = ft_sl(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

long	read_file(int fd, char *read_buff, char **res)
{
	long		rf_btr;

	rf_btr = read(fd, read_buff, BUFFER_SIZE);
	if (rf_btr < 0)
	{
		free(*res);
		return (-1);
	}
	if ((rf_btr == 0) && (ft_sl(*res) == 0))
	{
		free(*res);
		return (-1);
	}
	read_buff[rf_btr] = '\0';
	return (rf_btr);
}

long	read_more(int fd, long j, char **res, char *read_buff)
{
	long	res_size;

	res_size = ft_sl(*res);
	if (j == BUFFER_SIZE && (*res)[res_size - (res_size != 0)] != '\n')
	{
		j = read_file(fd, read_buff, res);
		if (j < 0)
			return (-1);
	}
	else
		j = 0;
	return (j);
}
