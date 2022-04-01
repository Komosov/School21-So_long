NAME	=	../so_long

SRCS_B	=	so_long_bonus.c \
			exits_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			map_convert_bonus.c \
			map_draw_bonus.c \
			map_read_bonus.c \
			mlx_init_bonus.c \
			movement_bonus.c \
			nodes_bonus.c \
			animation_bonus.c \
			enemy_steps_bonus.c \
			map_prepare_bonus.c \
			read_imgs_bonus.c

HEADERB	=	so_long_bonus.h

LIBFT	=	../libft/libft.a

LIBPF	=	../ft_printf/libftprintf.a

OBJS_B	=	${SRCS_B:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ../libft -lft

PFLAGS	=	-L ../ft_printf -lftprintf

MFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

%.o 	:	%.c ${HEADERB}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${LIBFT} ${LIBPF} ${OBJS_B}
			${CC} ${CFLAGS} ${OBJS_B} ${MFLAGS} ${LFLAGS} ${PFLAGS} -o ${NAME}

${LIBFT}:
			make -C ../libft all

${LIBPF}:
			make -C ../ft_printf all

%.o 	:	%.c ${HEADER_B}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} ${OBJS_B}

fclean	:	clean
			${RM} ${NAME}
			${RM} ${LIBFT}
			${RM} ${LIBPF}

re		:	fclean all
