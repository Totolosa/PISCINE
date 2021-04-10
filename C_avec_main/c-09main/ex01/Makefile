SRCS	= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

SRCSDIR	= srcs

SRCSFULL	= ${SRCS:%.c=${SRCSDIR}/%.c}

OBJS	= ${SRCSFULL:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
