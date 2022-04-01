/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:35:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/19 17:27:43 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	restore_prev_img(t_data *vl_k, int y, int x)
{
	if (vl_k->map[y][x] == 'E')
		draw_img_direct(vl_k, y, x, 'E');
	else
		draw_img_direct(vl_k, y, x, '0');
}

void	key_right_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'C')
	{
		(vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'P');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k);
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'X');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if ((vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == '0')
		|| (vl_k->map[vl_k->pl_y][vl_k->pl_x + 1] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x + 1, 'P');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x - 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
}

void	key_left_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'C')
	{
		(vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'P');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k);
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'X');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if ((vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == '0')
		|| (vl_k->map[vl_k->pl_y][vl_k->pl_x - 1] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y, vl_k->pl_x - 1, 'P');
		restore_prev_img(vl_k, vl_k->pl_y, vl_k->pl_x + 1);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
}

void	key_down_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'C')
	{
		(vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] = '0');
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'P');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k);
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'X');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if ((vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == '0')
		|| (vl_k->map[vl_k->pl_y + 1][vl_k->pl_x] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y + 1, vl_k->pl_x, 'P');
		restore_prev_img(vl_k, vl_k->pl_y - 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
}

void	key_up_act(t_data *vl_k)
{
	if (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'C')
	{
		vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] = '0';
		vl_k->coins--;
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'P');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'E')
	{
		if (vl_k->coins == 0)
			game_over(vl_k);
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'X');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
	else if ((vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == '0')
		|| (vl_k->map[vl_k->pl_y - 1][vl_k->pl_x] == 'P'))
	{
		draw_img_direct(vl_k, vl_k->pl_y - 1, vl_k->pl_x, 'P');
		restore_prev_img(vl_k, vl_k->pl_y + 1, vl_k->pl_x);
		ft_printf("Steps: %d, remain coins: %d\n", ++vl_k->steps, vl_k->coins);
	}
}
