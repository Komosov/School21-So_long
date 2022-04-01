/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:35:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:32:06 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	restore_prev_img(t_data *vl_k, int y, int x, char c)
{
	if (vl_k->map[y][x] == 'E')
		draw_img_direct(vl_k, y, x, 'E');
	else if ((c == 'L') || (c == 'R'))
		draw_img_direct(vl_k, y, x, 'H');
	else if ((c == 'U') || (c == 'D'))
		draw_img_direct(vl_k, y, x, 'V');
}

void	key_right_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'W')
		game_over(vl_k, -1);
	else if (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'C')
	{
		(vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'R');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'R');
		print_steps(vl_k);
	}
	else if (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k, 1);
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'F');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'R');
		print_steps(vl_k);
	}
	else if ((vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == '0')
		|| (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'R');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'R');
		print_steps(vl_k);
	}
}

void	key_left_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'W')
		game_over(vl_k, -1);
	if (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'C')
	{
		(vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'L');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'L');
		print_steps(vl_k);
	}
	else if (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k, 1);
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'A');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'L');
		print_steps(vl_k);
	}
	else if ((vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == '0')
		|| (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'L');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'L');
		print_steps(vl_k);
	}
}

void	key_down_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'W')
		game_over(vl_k, -1);
	if (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'C')
	{
		(vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'D');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'D');
		print_steps(vl_k);
	}
	else if (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k, 1);
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'S');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'D');
		print_steps(vl_k);
	}
	else if ((vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == '0')
		|| (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'D');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'D');
		print_steps(vl_k);
	}
}

void	key_up_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'W')
		game_over(vl_k, -1);
	if (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'C')
	{
		vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] = '0';
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'U');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'U');
		print_steps(vl_k);
	}
	else if (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k, 1);
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'Q');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'U');
		print_steps(vl_k);
	}
	else if ((vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == '0')
		|| (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'U');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'U');
		print_steps(vl_k);
	}
}
