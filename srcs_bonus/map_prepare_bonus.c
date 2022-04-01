/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prepare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:35:09 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:38:01 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static int	enemy_forward(t_data *vl_enb, int y, int x, int w)
{
	while (y < vl_enb->width - 2)
	{
		while (x < vl_enb->max_l - 2)
		{
			if (vl_enb->map[y][x] == '0')
			{
				vl_enb->map[y][x] = 'W';
				return (--w);
			}
			x++;
			x += vl_enb->i;
		}
		x = 0;
		y++;
	}
	return (w);
}

static int	enemy_backward(t_data *vl_enb, int y, int x, int w)
{
	while (2 < x)
	{
		while (2 < y)
		{
			if (vl_enb->map[y][x] == '0')
			{
				vl_enb->map[y][x] = 'W';
				return (--w);
			}
			y--;
		}
		y = vl_enb->width - 2;
		x--;
	}
	return (w);
}

void	enemy_random_set(t_data *vl_en)
{
	int		x;
	int		y;
	int		w_num;

	vl_en->i = 0;
	if (vl_en->max_l * vl_en->width / WORMS_RATE < 1)
		w_num = 1;
	else
		w_num = vl_en->max_l * vl_en->width / WORMS_RATE;
	x = rnd(&x, (vl_en->max_l - 2));
	y = rnd(&vl_en->width, (vl_en->width - 2));
	while ((w_num > 0) && (vl_en->i < 10000))
	{
		w_num = enemy_forward(vl_en, y, x, w_num);
		if (w_num > 0)
			w_num = enemy_backward(vl_en, y, x, w_num);
		vl_en->i++;
	}
}

void	starts_check(t_data *vl_dm)
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
