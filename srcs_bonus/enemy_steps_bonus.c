/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:06:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:19:49 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	worm_step_r(t_data *vl_ws)
{
	if ((vl_ws->j == vl_ws->pl_y) && (vl_ws->i + 1 == vl_ws->pl_x))
		game_over(vl_ws, -1);
	if (vl_ws->map[vl_ws->j][vl_ws->i + 1] == '0')
	{
		vl_ws->map[vl_ws->j][vl_ws->i + 1] = 'W';
		vl_ws->map[vl_ws->j][vl_ws->i] = '0';
		mlx_put_image_to_window(vl_ws->mlx_p, vl_ws->win_p,
			vl_ws->img->img_empty, vl_ws->i * IMG_SIZE, vl_ws->j * IMG_SIZE);
	}
	vl_ws->wsteps++;
}

static void	worm_step_l(t_data *vl_ws)
{
	if ((vl_ws->j == vl_ws->pl_y) && (vl_ws->i - 1 == vl_ws->pl_x))
		game_over(vl_ws, -1);
	if (vl_ws->map[vl_ws->j][vl_ws->i - 1] == '0')
	{
		vl_ws->map[vl_ws->j][vl_ws->i - 1] = 'W';
		vl_ws->map[vl_ws->j][vl_ws->i] = '0';
		mlx_put_image_to_window(vl_ws->mlx_p, vl_ws->win_p,
			vl_ws->img->img_empty, vl_ws->i * IMG_SIZE, vl_ws->j * IMG_SIZE);
	}
	vl_ws->wsteps++;
}

static void	worm_step_u(t_data *vl_ws)
{
	if ((vl_ws->j - 1 == vl_ws->pl_y) && (vl_ws->i == vl_ws->pl_x))
		game_over(vl_ws, -1);
	if (vl_ws->map[vl_ws->j - 1][vl_ws->i] == '0')
	{
		vl_ws->map[vl_ws->j - 1][vl_ws->i] = 'W';
		vl_ws->map[vl_ws->j][vl_ws->i] = '0';
		mlx_put_image_to_window(vl_ws->mlx_p, vl_ws->win_p,
			vl_ws->img->img_empty, vl_ws->i * IMG_SIZE, vl_ws->j * IMG_SIZE);
	}
	vl_ws->wsteps++;
}

static void	worm_step_d(t_data *vl_ws)
{
	if ((vl_ws->j + 1 == vl_ws->pl_y) && (vl_ws->i == vl_ws->pl_x))
		game_over(vl_ws, -1);
	if (vl_ws->map[vl_ws->j + 1][vl_ws->i] == '0')
	{
		vl_ws->map[vl_ws->j + 1][vl_ws->i] = 'W';
		vl_ws->map[vl_ws->j][vl_ws->i] = '0';
		mlx_put_image_to_window(vl_ws->mlx_p, vl_ws->win_p,
			vl_ws->img->img_empty, vl_ws->i * IMG_SIZE, vl_ws->j * IMG_SIZE);
	}
	vl_ws->wsteps++;
}

void	worm_step(t_data *vl_ws)
{
	if (((vl_ws->steps + vl_ws->wsteps) % 5) == 0)
		worm_step_r(vl_ws);
	else if (((vl_ws->steps + vl_ws->wsteps) % 3) == 0)
		worm_step_l(vl_ws);
	else if (((vl_ws->steps + vl_ws->wsteps) % 4) == 0)
		worm_step_u(vl_ws);
	else if (((vl_ws->steps + vl_ws->wsteps) % 2) == 0)
		worm_step_d(vl_ws);
	vl_ws->wsteps++;
}
