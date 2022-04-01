/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:09:36 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 21:41:29 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_malloc_create(t_data *vl)
{
	vl->j = 0;
	vl->map = (char **)malloc(sizeof(char *) * (vl->width));
	if (!vl->map)
		error_and_exit(ERR_000);
	while (vl->j < vl->width)
	{
		vl->map[vl->j] = (char *)malloc(sizeof(char) * (vl->max_l + 1));
		if (!vl->map[vl->j])
			error_and_exit(ERR_000);
		vl->j++;
	}
}

void	convert_map(t_data *vl)
{
	t_str_map	*tmp;

	tmp = vl->str_map;
	map_malloc_create(vl);
	vl->i = 0;
	vl->j = 0;
	while (vl->j < vl->width)
	{
		while (vl->i < vl->max_l)
		{
			vl->map[vl->j][vl->i] = tmp->map_line[vl->i];
			vl->i++;
		}
		vl->map[vl->j][vl->i] = '\0';
		tmp = tmp->next;
		vl->i = 0;
		vl->j++;
	}
	tmp = vl->str_map;
	ft_node_clear_list(&tmp);
}
