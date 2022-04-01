/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:01:17 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/22 20:02:48 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nError\n", 2);
	exit (EXIT_FAILURE);
}

int	ft_exit(t_data *vl_ex)
{
	int	i;

	i = vl_ex->width - 1;
	while (i >= 0)
	{
		free(vl_ex->map[i]);
		i--;
	}
	free(vl_ex->map);
	mlx_destroy_window(vl_ex->mlx_p, vl_ex->win_p);
	free(vl_ex->mlx_p);
	exit(EXIT_SUCCESS);
	return (0);
}

void	game_over(t_data *vl_go)
{
	ft_printf("You WIN!\n");
	ft_exit(vl_go);
}
