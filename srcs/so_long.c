/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:29:03 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/20 17:33:24 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_ber(char *str)
{
	int	l;

	l = ft_strlen(str) - 1;
	if ((str[l - 3] != '.') || (str[l - 2] != 'b')
		|| (str[l - 1] != 'e') || (str[l] != 'r'))
		error_and_exit(ERR_001);
}

static void	varlist_init(t_data *vl)
{
	vl->coins = 0;
	vl->exits = 0;
	vl->fd = 0;
	vl->j = 0;
	vl->i = 0;
	vl->max_l = 0;
	vl->min_l = -1;
	vl->pl_x = 0;
	vl->pl_y = 0;
	vl->starts = 0;
	vl->steps = 0;
	vl->width = 0;
}

int	rnd(void *ptr, int s)
{
	int		i;
	int		num;
	char	*str;

	num = ((int)&ptr / 4 / 3);
	if (num < 0)
		num = -num;
	str = ft_itoa(num);
	i = ft_atoi(&str[ft_strlen(str) - 1]);
	num = (int)((double)s / 10 * (double)i);
	free(str);
	if (i == 9)
		num = s;
	return (num);
}

int	main(int argc, char **argv)
{
	t_data	vlist;

	if (argc != 2)
		error_and_exit(ERR_005);
	check_ber(argv[1]);
	varlist_init(&vlist);
	read_and_check_map(argv[1], &vlist);
	convert_map(&vlist);
	ft_mlx_init(&vlist);
	draw_map(&vlist);
	mlx_loop(vlist.mlx_p);
	return (0);
}
