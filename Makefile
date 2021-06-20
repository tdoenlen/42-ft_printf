SRCS	= ft_printf.c ft_printf_utils.c put.c str.c argtoa/ctoa.c \
		  argtoa/itoa.c argtoa/uitoa.c argtoa/stoa.c
OBJS	= ${SRCS:%.c=%.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= libftprintf.a

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:		
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
