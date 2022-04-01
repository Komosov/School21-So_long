/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:11:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 22:20:20 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_img_direct_player(t_data *vl_dr, int y, int x, char c)
{
	if (c == 'U')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player[0], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'L')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player[1], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'D')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player[2], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'R')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player[3], x * IMG_SIZE, y * IMG_SIZE);
	vl_dr->pl_x = x;
	vl_dr->pl_y = y;
}

static void	draw_img_direct_player_exit(t_data *vl_dr, int y, int x, char c)
{
	if (c == 'Q')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exitp[0], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'A')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exitp[1], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'S')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exitp[2], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'F')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exitp[3], x * IMG_SIZE, y * IMG_SIZE);
	vl_dr->pl_x = x;
	vl_dr->pl_y = y;
}

void	draw_img_direct(t_data *vl_dr, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_wall, x * IMG_SIZE, y * IMG_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_empty, x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'H')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_track[0], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'V')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_track[1], x * IMG_SIZE, y * IMG_SIZE);
	else if ((c == 'U') || (c == 'L') || (c == 'D') || (c == 'R'))
		draw_img_direct_player(vl_dr, y, x, c);
	else if ((c == 'Q') || (c == 'A') || (c == 'S') || (c == 'F'))
		draw_img_direct_player_exit(vl_dr, y, x, c);
	else if (c == 'C')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_coin, x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exit, x * IMG_SIZE, y * IMG_SIZE);
}

static void	draw_img_from_map(t_data *vl_dr, int y, int x)
{
	if (vl_dr->map[y][x] == '1')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_wall, x * IMG_SIZE, y * IMG_SIZE);
	else if (vl_dr->map[y][x] == '0')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_empty, x * IMG_SIZE, y * IMG_SIZE);
	else if (vl_dr->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player[3], x * IMG_SIZE, y * IMG_SIZE);
		vl_dr->pl_x = x;
		vl_dr->pl_y = y;
	}
	else if (vl_dr->map[y][x] == 'C')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_coin, x * IMG_SIZE, y * IMG_SIZE);
	else if (vl_dr->map[y][x] == 'E')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exit, x * IMG_SIZE, y * IMG_SIZE);
}

void	draw_map(t_data *vl_dm)
{
	vl_dm->exits = 0;
	starts_check(vl_dm);
	enemy_random_set(vl_dm);
	vl_dm->i = 0;
	vl_dm->j = 0;
	while (vl_dm->j < vl_dm->width)
	{
		while (vl_dm->i < vl_dm->max_l)
		{
			draw_img_from_map(vl_dm, vl_dm->j, vl_dm->i);
			vl_dm->i++;
		}
		vl_dm->i = 0;
		vl_dm->j++;
	}
	mlx_string_put(vl_dm->mlx_p, vl_dm->win_p, (IMG_SIZE / 4),
		IMG_SIZE / 4, -1, "Steps: 0");
}
