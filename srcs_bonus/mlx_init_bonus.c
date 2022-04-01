/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:22:28 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/24 20:09:51 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	deal_key(int key, void *ptr)
{
	if (key == KEY_ESC)
		ft_exit(ptr);
	else if ((key == KEY_D) || (key == KEY_ARR_R))
		key_right_act(ptr);
	else if ((key == KEY_A) || (key == KEY_ARR_L))
		key_left_act(ptr);
	else if ((key == KEY_W) || (key == KEY_ARR_U))
		key_up_act(ptr);
	else if ((key == KEY_S) || (key == KEY_ARR_D))
		key_down_act(ptr);
	return (0);
}

void	struct_imgs_init(t_data *vl_r)
{
	vl_r->img = malloc(sizeof(t_imgs));
	if (!vl_r->img)
		error_and_exit(ERR_000);
	vl_r->img->img_wall = NULL;
	vl_r->img->img_empty = NULL;
	vl_r->img->img_coin = NULL;
	vl_r->img->img_exit = NULL;
	vl_r->img->img_track[0] = NULL;
	vl_r->img->img_track[1] = NULL;
	vl_r->i = 0;
	while (vl_r->i <= 3)
		vl_r->img->img_player[vl_r->i++] = NULL;
	vl_r->i = 0;
	while (vl_r->i <= 3)
		vl_r->img->img_exitp[vl_r->i++] = NULL;
	vl_r->i = 0;
	while (vl_r->i <= 7)
		vl_r->img->img_exito[vl_r->i++] = NULL;
	vl_r->i = 0;
	while (vl_r->i <= 7)
		vl_r->img->img_worm[vl_r->i++] = NULL;
}

void	struct_imgs_check(t_data *vl_r)
{
	if ((!vl_r->img->img_wall) || (!vl_r->img->img_empty)
		|| (!vl_r->img->img_coin) || (!vl_r->img->img_player[0])
		|| (!vl_r->img->img_player[1]) || (!vl_r->img->img_player[2])
		|| (!vl_r->img->img_player[3]) || (!vl_r->img->img_exit)
		|| (!vl_r->img->img_track[0]) || (!vl_r->img->img_track[1])
		|| (!vl_r->img->img_exitp[0]) || (!vl_r->img->img_exitp[1])
		|| (!vl_r->img->img_exitp[2]) || (!vl_r->img->img_exitp[3])
		|| (!vl_r->img->img_exito[0]) || (!vl_r->img->img_exito[1])
		|| (!vl_r->img->img_exito[2]) || (!vl_r->img->img_exito[3])
		|| (!vl_r->img->img_exito[4]) || (!vl_r->img->img_exito[5])
		|| (!vl_r->img->img_exito[6]) || (!vl_r->img->img_exito[7])
		|| (!vl_r->img->img_worm[0]) || (!vl_r->img->img_worm[1])
		|| (!vl_r->img->img_worm[2]) || (!vl_r->img->img_worm[3])
		|| (!vl_r->img->img_worm[4]) || (!vl_r->img->img_worm[5])
		|| (!vl_r->img->img_worm[6]) || (!vl_r->img->img_worm[7]))
		error_and_exit(ERR_008);
}

void	print_steps(t_data *vl_an)
{
	char	*word;
	char	*num;
	char	*str;

	vl_an->steps++;
	word = "Steps: ";
	num = ft_itoa(vl_an->steps);
	str = ft_strjoin(word, num);
	mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
		vl_an->img->img_wall, 0 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
		vl_an->img->img_wall, 1 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
		vl_an->img->img_wall, 2 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
		vl_an->img->img_wall, 3 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(vl_an->mlx_p, vl_an->win_p,
		vl_an->img->img_wall, 4 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_string_put(vl_an->mlx_p, vl_an->win_p, (IMG_SIZE / 4),
		IMG_SIZE / 4, -1, str);
	free(str);
	free(num);
}

void	ft_mlx_init(t_data *vl_mlx)
{
	vl_mlx->mlx_p = mlx_init();
	if (vl_mlx->mlx_p == NULL)
		error_and_exit(ERR_009);
	vl_mlx->win_p = mlx_new_window(vl_mlx->mlx_p,
			(IMG_SIZE * vl_mlx->max_l), (IMG_SIZE * vl_mlx->width),
			"So_long BONUS");
	if (vl_mlx->win_p == NULL)
		error_and_exit(ERR_009);
	read_imgs(vl_mlx);
	mlx_hook(vl_mlx->win_p, CROSS, 0, ft_exit, vl_mlx);
	mlx_loop_hook(vl_mlx->mlx_p, animation, vl_mlx);
	mlx_key_hook(vl_mlx->win_p, deal_key, vl_mlx);
}
