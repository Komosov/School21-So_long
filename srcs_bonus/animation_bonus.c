/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:37:18 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:20:33 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ani_exits(t_data *vl_an)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < vl_an->width)
	{
		while (x < vl_an->max_l)
		{
			if (vl_an->map[y][x] == 'E')
				mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
					vl_an->img->img_exito[vl_an->hook],
					x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	ani_worms(t_data *vl_an)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < vl_an->width)
	{
		while (x < vl_an->max_l)
		{
			if (vl_an->map[y][x] == 'W')
				mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
					vl_an->img->img_worm[vl_an->hook],
					x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	worms_move(t_data *vl_wm)
{
	vl_wm->j = 0;
	vl_wm->i = 0;
	while (vl_wm->j < vl_wm->width - 2)
	{
		while (vl_wm->i < vl_wm->max_l - 2)
		{
			if (vl_wm->map[vl_wm->j][vl_wm->i] == 'W')
			{
				worm_step(vl_wm);
				vl_wm->i++;
			}
			vl_wm->i++;
		}
		vl_wm->i = 0;
		vl_wm->j++;
	}
}

int	animation(t_data *vl_an)
{
	if (vl_an->counter < TICKS_PER_FRAME)
		vl_an->counter++;
	else
	{
		if (vl_an->coins == 0)
			ani_exits(vl_an);
		ani_worms(vl_an);
		vl_an->counter = 0;
		vl_an->hook++;
	}
	if (vl_an->hook > 7)
	{
		vl_an->hook = 0;
		worms_move(vl_an);
	}
	return (0);
}
