/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:47:58 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/23 22:56:27 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	read_imgs_exit_player(t_data *vl_r)
{
	int	x;

	x = 0;
	vl_r->img->img_exitp[0] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_U, &x, &x);
	vl_r->img->img_exitp[1] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_L, &x, &x);
	vl_r->img->img_exitp[2] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_D, &x, &x);
	vl_r->img->img_exitp[3] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_R, &x, &x);
}

static void	read_imgs_exit(t_data *vl_r)
{
	int	x;

	x = 0;
	vl_r->img->img_exito[0] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_0, &x, &x);
	vl_r->img->img_exito[1] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_1, &x, &x);
	vl_r->img->img_exito[2] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_2, &x, &x);
	vl_r->img->img_exito[3] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_3, &x, &x);
	vl_r->img->img_exito[4] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_4, &x, &x);
	vl_r->img->img_exito[5] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_5, &x, &x);
	vl_r->img->img_exito[6] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_6, &x, &x);
	vl_r->img->img_exito[7] = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT_7, &x, &x);
}

static void	read_imgs_worm(t_data *vl_r)
{
	int	x;

	x = 0;
	vl_r->img->img_worm[0] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_0, &x, &x);
	vl_r->img->img_worm[1] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_1, &x, &x);
	vl_r->img->img_worm[2] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_2, &x, &x);
	vl_r->img->img_worm[3] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_3, &x, &x);
	vl_r->img->img_worm[4] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_4, &x, &x);
	vl_r->img->img_worm[5] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_5, &x, &x);
	vl_r->img->img_worm[6] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_6, &x, &x);
	vl_r->img->img_worm[7] = mlx_xpm_file_to_image(vl_r->mlx_p,
			WORM_7, &x, &x);
}

void	read_imgs(t_data *vl_r)
{
	int	x;

	struct_imgs_init(vl_r);
	x = 0;
	vl_r->img->img_wall = mlx_xpm_file_to_image(vl_r->mlx_p, WALL, &x, &x);
	vl_r->img->img_empty = mlx_xpm_file_to_image(vl_r->mlx_p, EMPTY, &x, &x);
	vl_r->img->img_coin = mlx_xpm_file_to_image(vl_r->mlx_p, COIN, &x, &x);
	vl_r->img->img_player[0] = mlx_xpm_file_to_image(vl_r->mlx_p,
			PLAYER_U_0, &x, &x);
	vl_r->img->img_player[1] = mlx_xpm_file_to_image(vl_r->mlx_p,
			PLAYER_L_1, &x, &x);
	vl_r->img->img_player[2] = mlx_xpm_file_to_image(vl_r->mlx_p,
			PLAYER_D_2, &x, &x);
	vl_r->img->img_player[3] = mlx_xpm_file_to_image(vl_r->mlx_p,
			PLAYER_R_3, &x, &x);
	vl_r->img->img_exit = mlx_xpm_file_to_image(vl_r->mlx_p,
			EXIT, &x, &x);
	vl_r->img->img_track[0] = mlx_xpm_file_to_image(vl_r->mlx_p,
			TRACK_H_0, &x, &x);
	vl_r->img->img_track[1] = mlx_xpm_file_to_image(vl_r->mlx_p,
			TRACK_V_1, &x, &x);
	read_imgs_exit_player(vl_r);
	read_imgs_exit(vl_r);
	read_imgs_worm(vl_r);
	struct_imgs_check(vl_r);
}
