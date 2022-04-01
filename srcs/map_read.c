/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:51:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/24 20:52:22 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	items_count(char c, t_data *vl)
{
	if (c == 'C')
		vl->coins++;
	else if (c == 'E')
		vl->exits++;
	else if (c == 'P')
		vl->starts++;
}

static void	check_line(char *s, t_data *vl)
{
	if (s == NULL)
		return ;
	if ((ft_strlen(s) != 0) && (s[ft_strlen(s) - 1] == '\n'))
		s[ft_strlen(s) - 1] = '\0';
	vl->j = ft_strlen(s);
	if ((vl->j < vl->min_l) || (vl->min_l == -1))
		vl->min_l = vl->j;
	if (vl->j > vl->max_l)
		vl->max_l = vl->j;
	vl->i = 0;
	while ((vl->i < vl->j) && ((s[vl->i] == '0') || (s[vl->i] == '1')
			|| (s[vl->i] == 'C') || (s[vl->i] == 'E') || (s[vl->i] == 'P')))
	{
		items_count(s[vl->i], vl);
		vl->i++;
	}
	if (((s[vl->i] == '0') || (s[vl->i] == '1') || (s[vl->i] == 'C')
			|| (s[vl->i] == 'E') || (s[vl->i] == 'P')) || (s[vl->i] == '\0'))
		return ;
	else
	{
		close(vl->fd);
		ft_putchar_fd(s[vl->i], 2);
		error_and_exit(ERR_002);
	}
}

static void	check_map(t_data *vl)
{
	t_str_map	*tmp;

	tmp = vl->str_map;
	if ((vl->coins < 1) || (vl->exits < 1) || (vl->starts < 1))
		error_and_exit(ERR_007);
	if (vl->max_l != vl->min_l)
		error_and_exit(ERR_004);
	vl->width = ft_nodes_count(tmp);
}

static void	check_wals(t_data *vl)
{
	t_str_map	*tmp;
	char		*str;

	tmp = vl->str_map;
	vl->j = vl->width;
	while (vl->j > 0)
	{
		vl->i = 0;
		str = tmp->map_line;
		if ((vl->j == 1) || (vl->j == vl->width))
		{
			while ((str[vl->i] != '\0') && (str[vl->i] == '1'))
				vl->i++;
			if ((str[vl->i] != '1') && (vl->i != (int)(ft_strlen(str))))
				error_and_exit(ERR_006);
		}
		else
		{
			if ((str[0] != '1') || (str[ft_strlen(str) - 1] != '1'))
				error_and_exit(ERR_006);
		}
		tmp = tmp->next;
		vl->j--;
	}
}

void	read_and_check_map(char *argv, t_data *vl)
{
	char	*line;
	int		i;

	vl->fd = open(argv, O_RDONLY);
	if (vl->fd < 1)
	{
		perror(NULL);
		error_and_exit(ERR_003);
	}
	line = get_next_line(vl->fd);
	check_line(line, vl);
	vl->str_map = ft_node_create(line, 0);
	i = 1;
	while (line)
	{
		line = get_next_line(vl->fd);
		check_line(line, vl);
		if ((line != NULL) && (line[0] != '\0') && (line[0] != '\n'))
			ft_node_push_back(&(vl->str_map), line, i++);
	}
	free(line);
	close(vl->fd);
	check_map(vl);
	check_wals(vl);
}
