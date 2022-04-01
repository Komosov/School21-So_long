/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:31:04 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/19 20:09:21 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long	transfer_to_res(char *ttr_s_trsfr, char **res)
{
	long	ttr_i;
	long	tr_sz;

	ttr_i = 0;
	tr_sz = ft_sl(ttr_s_trsfr);
	while ((ttr_i < tr_sz) && (ttr_s_trsfr[ttr_i] != '\n'))
	{
		(*res)[ttr_i] = ttr_s_trsfr[ttr_i];
		ttr_i++;
	}
	return (ttr_i);
}

char	*transfer_crop(long tc_i, long tc_btr, char *tc_s_trsfr, char *res)
{
	long	j;

	res[tc_i] = tc_s_trsfr[tc_i];
	res[tc_i + 1] = '\0';
	j = 0;
	while (tc_i < tc_btr)
	{
		tc_i++;
		tc_s_trsfr[j] = tc_s_trsfr[tc_i];
		j++;
	}
	tc_s_trsfr[j] = '\0';
	return (res);
}

void	zeroer(long i, char **res, char *zr_s_trsfr)
{
	zr_s_trsfr[0] = '\0';
	(*res)[i] = '\0';
}

char	*search_and_join(long sj_btr, char *sj_rbf, char **res, char *sj_strsfr)
{
	char	str_tmp[BUFFER_SIZE + 1];
	long	j;
	long	m;

	j = 0;
	while (j < sj_btr && sj_rbf[j] != '\n')
	{
		str_tmp[j] = sj_rbf[j];
		j++;
	}
	str_tmp[j] = '\0';
	if (sj_rbf[j] == '\n')
	{
		str_tmp[j] = '\n';
		str_tmp[j + 1] = '\0';
	}
	*res = ft_strjoin_gnl(*res, str_tmp);
	m = 0;
	while (j < sj_btr && sj_rbf[j])
	{
		j++;
		sj_strsfr[m] = sj_rbf[j];
		m++;
	}
	return (*res);
}

char	*get_next_line(int fd)
{
	static char	s_transfer[FD_LIMIT][BUFFER_SIZE + 1];
	char		read_buff[BUFFER_SIZE + 1];
	char		*res;
	long		i;

	if ((read(fd, read_buff, 0) < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_sl_to_n(s_transfer[fd]) + 1));
	if (!res)
		return (NULL);
	i = transfer_to_res(s_transfer[fd], &res);
	if (s_transfer[fd][i] == '\n')
		return (transfer_crop(i, ft_sl(s_transfer[fd]), s_transfer[fd], res));
	zeroer(i, &res, s_transfer[fd]);
	i = read_file(fd, read_buff, &res);
	if (i < 0)
		return (NULL);
	while (i > 0)
	{
		res = search_and_join(i, read_buff, &res, s_transfer[fd]);
		i = read_more(fd, i, &res, read_buff);
		if (i < 0)
			return (NULL);
	}
	return (res);
}
