NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_strlen_pf.c \
			ft_write_number.c \
			ft_c_d_i_processing.c \
			ft_s_u_p_processing.c \
			ft_putstr_fd_pf.c

HEADER	=	ft_printf.h

OBJS	=	${SRCS:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

${NAME}	:	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

%.o 	:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} ${OBJS} ${OBJS_B}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all
