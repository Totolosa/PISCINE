
SRCS		= main.c tools.c parsing_dict.c parsing_dict2.c check_dict.c print_input.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS}  -o ${<:.c=.o} -c $<

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.SUFFIXES:	.c.o.h
.PHONY:		all clean fclean re
