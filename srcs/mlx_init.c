/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:22:28 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/24 20:06:29 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	deal_key(int key, void *ptr)
{
	if (key == KEY_ESC)
		ft_exit(ptr);
	else if ((key == KEY_D) || (key == KEY_ARR_R))
		key_right_act(ptr);
	else if ((key == KEY_A) || (key == KEY_ARR_L))
		key_left_act(ptr);
	else if ((key == KEY_W) || (key == KEY_ARR_U))
		key_up_act(ptr);
	else if ((key == KEY_S) || (key == KEY_ARR_D))
		key_down_act(ptr);
	return (0);
}

static void	read_imgs(t_data *vl_r)
{
	int	x;

	x = 0;
	vl_r->img = malloc(sizeof(t_imgs));
	if (!vl_r->img)
		error_and_exit(ERR_000);
	vl_r->img->img_wall = NULL;
	vl_r->img->img_empty = NULL;
	vl_r->img->img_coin = NULL;
	vl_r->img->img_player = NULL;
	vl_r->img->img_exit = NULL;
	vl_r->img->img_win = NULL;
	vl_r->img->img_wall = mlx_xpm_file_to_image(vl_r->mlx_p, WALL, &x, &x);
	vl_r->img->img_empty = mlx_xpm_file_to_image(vl_r->mlx_p, EMPTY, &x, &x);
	vl_r->img->img_coin = mlx_xpm_file_to_image(vl_r->mlx_p, COIN, &x, &x);
	vl_r->img->img_player = mlx_xpm_file_to_image(vl_r->mlx_p, PLAYER, &x, &x);
	vl_r->img->img_exit = mlx_xpm_file_to_image(vl_r->mlx_p, EXIT, &x, &x);
	vl_r->img->img_exitp = mlx_xpm_file_to_image(vl_r->mlx_p, EXITP, &x, &x);
	if ((!vl_r->img->img_wall) || (!vl_r->img->img_empty)
		|| (!vl_r->img->img_coin) || (!vl_r->img->img_player)
		|| (!vl_r->img->img_exit) || (!vl_r->img->img_exitp))
		error_and_exit(ERR_008);
}

void	ft_mlx_init(t_data *vl_mlx)
{
	vl_mlx->mlx_p = mlx_init();
	if (vl_mlx->mlx_p == NULL)
		error_and_exit(ERR_009);
	vl_mlx->win_p = mlx_new_window(vl_mlx->mlx_p,
			(IMG_SIZE * vl_mlx->max_l), (IMG_SIZE * vl_mlx->width), "So_long");
	if (vl_mlx->win_p == NULL)
		error_and_exit(ERR_009);
	read_imgs(vl_mlx);
	mlx_hook(vl_mlx->win_p, CROSS, 0, ft_exit, vl_mlx);
	mlx_key_hook(vl_mlx->win_p, deal_key, vl_mlx);
}
