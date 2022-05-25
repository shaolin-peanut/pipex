SRC = ${addprefix src/, main.c	\
	  utils.c	\
	  errormsg.c	\
	  process.c	\
	  parse_ops.c	\
	  get_next_line_utils.c	\
	  ft_split.c}
OBJ = ${SRC:.c=.o}
HEAD = src/pipex.h
NAME = pipex
CFLAGS = -Wall -Werror -Wextra 
OFLAGS = -fsanitize=address -g3
CC = gcc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJ} ${HEAD}
	${CC} ${OFLAGS} ${OBJ} -o ${NAME}


fclean:	clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re:	fclean all

lldb: ${OBJ}
	${CC} ${SRC} -g -o ${NAME}
	lldb ${NAME}

.PHONY: all fclean clean re
