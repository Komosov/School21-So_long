/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:08:50 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/16 23:16:58 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_str_map	*ft_node_create(char *line, int line_number)
{
	t_str_map	*node;

	node = (t_str_map *)malloc(sizeof(t_str_map));
	if (!node)
		return (NULL);
	node->map_line = line;
	node->line_index = line_number;
	node->next = NULL;
	return (node);
}

void	ft_node_push_back(t_str_map **list, char *line, int line_number)
{
	t_str_map	*new_node;
	t_str_map	*tmp;

	tmp = *list;
	new_node = ft_node_create(line, line_number);
	if (!new_node)
	{
		ft_node_clear_list(list);
		error_and_exit(ERR_000);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	ft_nodes_count(t_str_map *list)
{
	int			i;
	t_str_map	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_node_clear_list(t_str_map **list)
{
	t_str_map	*tmp_clear;
	t_str_map	*tmp_next;

	tmp_next = *list;
	*list = NULL;
	while (tmp_next != NULL)
	{
		tmp_clear = tmp_next;
		tmp_next = tmp_next->next;
		free(tmp_clear->map_line);
		free(tmp_clear);
	}
}
