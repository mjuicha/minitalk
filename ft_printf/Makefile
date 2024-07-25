SRCS  = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_hex.c

OBJS  = ${SRCS:%.c=%.o}

NAME  = libftprintf.a
AR 	  = ar rc 
CC	  = cc
FLAGS = -Wall -Wextra -Werror
RM	  = rm -f

all		 :	${NAME}

%.o 	 :		%.c		ft_printf.h
			${CC} ${FLAGS} -c $<

${NAME}	 :	${OBJS}
			${AR} ${NAME} ${OBJS}

clean	 :
			${RM} ${OBJS}

fclean:			clean
			${RM} ${NAME}

re:				fclean all