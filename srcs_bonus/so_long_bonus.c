/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:29:03 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:40:46 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	vl->wsteps = 0;
	vl->width = 0;
	vl->hook = 0;
	vl->counter = TICKS_PER_FRAME;
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
