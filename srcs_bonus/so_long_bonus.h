/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:10:33 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/24 22:10:43 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define ERR_000 "Memory isn't allocated."
# define ERR_001 "The extension is not \".ber\"."
# define ERR_002 " <- forbidden symbol detected."
# define ERR_003 "Can't open the file."
# define ERR_004 "Map is not rectangular."
# define ERR_005 "One and the only one argument must be."
# define ERR_006 "The map is NOT closed/surrounded by walls."
# define ERR_007 "Exits, collectibles or starts less, than necessary."
# define ERR_008 "Some image is not loaded."
# define ERR_009 "MLX memory isn't allocated."
# define TICKS_PER_FRAME 2000
# define WORMS_RATE 100
# define WALL "pictures/mount.xpm"
# define EMPTY "pictures/sand.xpm"
# define COIN "pictures/spice.xpm"
# define PLAYER_U_0 "pictures/harvester_u_0.xpm"
# define PLAYER_L_1 "pictures/harvester_l_1.xpm"
# define PLAYER_D_2 "pictures/harvester_d_2.xpm"
# define PLAYER_R_3 "pictures/harvester_r_3.xpm"
# define TRACK_H_0 "pictures/track_h.xpm"
# define TRACK_V_1 "pictures/track_v.xpm"
# define EXIT "pictures/rock.xpm"
# define EXIT_U "pictures/rock_u.xpm"
# define EXIT_L "pictures/rock_l.xpm"
# define EXIT_D "pictures/rock_d.xpm"
# define EXIT_R "pictures/rock_r.xpm"
# define EXIT_0 "pictures/exit0.xpm"
# define EXIT_1 "pictures/exit1.xpm"
# define EXIT_2 "pictures/exit2.xpm"
# define EXIT_3 "pictures/exit3.xpm"
# define EXIT_4 "pictures/exit4.xpm"
# define EXIT_5 "pictures/exit5.xpm"
# define EXIT_6 "pictures/exit6.xpm"
# define EXIT_7 "pictures/exit7.xpm"
# define WORM_0 "pictures/sandworm0.xpm"
# define WORM_1 "pictures/sandworm1.xpm"
# define WORM_2 "pictures/sandworm2.xpm"
# define WORM_3 "pictures/sandworm3.xpm"
# define WORM_4 "pictures/sandworm4.xpm"
# define WORM_5 "pictures/sandworm3.xpm"
# define WORM_6 "pictures/sandworm2.xpm"
# define WORM_7 "pictures/sandworm1.xpm"
# define FD_LIMIT OPEN_MAX
# define BUFFER_SIZE 1000
# define IMG_SIZE 32
# define KEY_ESC 53
# define KEY_ARR_L 123
# define KEY_ARR_R 124
# define KEY_ARR_D 125
# define KEY_ARR_U 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define CROSS 17

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_str_map
{
	char				*map_line;
	int					line_index;
	struct s_str_map	*next;
}	t_str_map;

typedef struct s_imgs
{
	int		img_width;
	int		img_height;
	void	*img_wall;
	void	*img_player[4];
	void	*img_track[2];
	void	*img_coin;
	void	*img_exit;
	void	*img_exitp[4];
	void	*img_exito[8];
	void	*img_worm[8];
	void	*img_empty;
}	t_imgs;

typedef struct s_data
{
	int			fd;
	int			min_l;
	int			max_l;
	int			coins;
	int			exits;
	int			starts;
	int			i;
	int			j;
	void		*mlx_p;
	void		*win_p;
	char		**map;
	int			width;
	int			pl_x;
	int			pl_y;
	int			steps;
	int			wsteps;
	int			hook;
	int			counter;
	t_str_map	*str_map;
	t_imgs		*img;
}	t_data;

void		error_and_exit(char *message);
int			ft_exit(t_data *vl_ex);
void		game_over(t_data *vl_go, int a);
int			rnd(void *ptr, int s);
int			animation(t_data *vl_an);
void		print_steps(t_data *vl_an);
void		worm_step(t_data *vl_ws);
void		starts_check(t_data *vl_dm);
void		enemy_random_set(t_data *vl_en);
void		read_imgs(t_data *vl_r);
void		struct_imgs_init(t_data *vl_r);
void		struct_imgs_check(t_data *vl_r);
char		*get_next_line(int fd);
long		ft_sl(const char *s);
long		ft_sl_to_n(const char *s);
char		*ft_strjoin_gnl(char *s1, char *s2);
long		read_file(int fd, char *read_buff, char **res);
long		read_more(int fd, long j, char **res, char *read_buff);
t_str_map	*ft_node_create(char *line, int line_number);
void		ft_node_push_back(t_str_map **list, char *line, int line_number);
int			ft_nodes_count(t_str_map *list);
void		ft_node_clear_list(t_str_map **list);
void		read_and_check_map(char *argv, t_data *vl);
void		convert_map(t_data *vl);
void		draw_map(t_data *vl_dm);
void		ft_mlx_init(t_data *vl_mlx);
void		draw_img_direct(t_data *vl_dr, int y, int x, char c);
void		key_right_act(t_data *vl_k);
void		key_left_act(t_data *vl_k);
void		key_down_act(t_data *vl_k);
void		key_up_act(t_data *vl_k);

#endif
