NAME	= BSQ
SRCS	= creation_tab_int.c ft_atoi.c main.c parser.c resolve.c
HDRS	= ft_atoi.h parser.h resolve.h
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}
RM		= rm -f

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
.c.o:
			${CC} ${CFLAGS} -c $< ${addprefix -include , ${HDRS}} -o ${<:.c=.o}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
