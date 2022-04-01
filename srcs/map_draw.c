/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:11:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/19 17:02:35 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	write_y_x(t_data *vl_gt, int y, int x)
{
		vl_gt->pl_x = x;
		vl_gt->pl_y = y;
}

void	draw_img_direct(t_data *vl_dr, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_wall, x * IMG_SIZE, y * IMG_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_empty, x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'P')
	{
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_player, x * IMG_SIZE, y * IMG_SIZE);
		write_y_x(vl_dr, y, x);
	}
	else if (c == 'X')
	{
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exitp, x * IMG_SIZE, y * IMG_SIZE);
		write_y_x(vl_dr, y, x);
	}
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
			vl_dr->img->img_player, x * IMG_SIZE, y * IMG_SIZE);
		write_y_x(vl_dr, y, x);
	}
	else if (vl_dr->map[y][x] == 'C')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_coin, x * IMG_SIZE, y * IMG_SIZE);
	else if (vl_dr->map[y][x] == 'E')
		mlx_put_image_to_window(vl_dr->mlx_p, vl_dr->win_p,
			vl_dr->img->img_exit, x * IMG_SIZE, y * IMG_SIZE);
}

static void	starts_check(t_data *vl_dm)
{
	vl_dm->fd = rnd(&vl_dm->fd, vl_dm->starts);
	while (vl_dm->starts > 1)
	{
		vl_dm->i = 0;
		vl_dm->j = 0;
		while (vl_dm->j < vl_dm->width)
		{
			while (vl_dm->i < vl_dm->max_l)
			{
				if ((vl_dm->map[vl_dm->j][vl_dm->i] == 'P')
					&& (vl_dm->starts > 1))
				{
					if (vl_dm->fd != vl_dm->exits)
					{
						vl_dm->map[vl_dm->j][vl_dm->i] = '0';
						vl_dm->starts--;
					}
				vl_dm->exits++;
				}
			vl_dm->i++;
			}
			vl_dm->i = 0;
			vl_dm->j++;
		}
	}
}

void	draw_map(t_data *vl_dm)
{
	vl_dm->exits = 0;
	starts_check(vl_dm);
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
}
