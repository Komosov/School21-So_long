NAME	=	../so_long

SRCS	=	so_long.c \
			exits.c \
			get_next_line.c \
			get_next_line_utils.c \
			map_convert.c \
			map_draw.c \
			map_read.c \
			mlx_init.c \
			movement.c \
			nodes.c

HEADER	=	so_long.h

LIBFT	=	../libft/libft.a

LIBPF	=	../ft_printf/libftprintf.a

OBJS	=	${SRCS:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ../libft -lft

PFLAGS	=	-L ../ft_printf -lftprintf

MFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

%.o 	:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${LIBFT} ${LIBPF} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${MFLAGS} ${LFLAGS} ${PFLAGS} -o ${NAME}

${LIBFT}:
			make -C ../libft all

${LIBPF}:
			make -C ../ft_printf all

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}
			${RM} ${LIBFT}
			${RM} ${LIBPF}

re		:	fclean all
