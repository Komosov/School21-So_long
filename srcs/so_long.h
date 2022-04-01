/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:10:33 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/24 22:09:39 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define WALL "pictures/wall.xpm"
# define EMPTY "pictures/empty.xpm"
# define COIN "pictures/coin.xpm"
# define PLAYER "pictures/player.xpm"
# define EXIT "pictures/exit.xpm"
# define EXITP "pictures/exit-player.xpm"
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
	void	*img_win;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	void	*img_exitp;
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
	t_str_map	*str_map;
	t_imgs		*img;
}	t_data;

void		error_and_exit(char *message);
int			ft_exit(t_data *vl_ex);
void		game_over(t_data *vl_go);
int			rnd(void *ptr, int s);
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
