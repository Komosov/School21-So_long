NAME	=	so_long

SRCS	=	./srcs/so_long.c \
			./srcs/exits.c \
			./srcs/get_next_line.c \
			./srcs/get_next_line_utils.c \
			./srcs/map_convert.c \
			./srcs/map_draw.c \
			./srcs/map_read.c \
			./srcs/mlx_init.c \
			./srcs/movement.c \
			./srcs/nodes.c

HEADER	=	./srcs/so_long.h

LIBFT	=	./libft/libft.a

LIBPF	=	./ft_printf/libftprintf.a

OBJS	=	${SRCS:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ./libft -lft

PFLAGS	=	-L ./ft_printf -lftprintf

MFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

%.o 	:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${LIBFT} ${LIBPF} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${MFLAGS} ${LFLAGS} ${PFLAGS} -o ${NAME}

${LIBFT}:
			make -C ./libft all

${LIBPF}:
			make -C ./ft_printf all

bonus	:
			make -C ./srcs_bonus all

clean	:
			make -C ./srcs clean
			make -C ./srcs_bonus clean
			make -C ./libft clean
			make -C ./ft_printf clean

fclean	:	clean
			${RM} ${NAME}
			${RM} ${LIBFT}
			${RM} ${LIBPF}

re		:	fclean all
