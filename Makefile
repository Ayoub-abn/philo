NAME = philo
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
 CFLAGS = -Wall -Wextra -Werror 
SRC = data_init.c ft_putstr_fd.c main.c monitor.c parsing.c philo.c routine.c tools.c
OBG = ${SRC:.c=.o}

%.o:%.c
	@${CC} ${CFLAGS} -g -c $< -o $@
	@echo "✅"

all:${NAME}

${NAME}:${OBG}
	@${CC} ${CFLAGS} ${OBG} -o ${NAME}
	@echo "💯"


clean:
	@rm -f ${OBG}
	@echo "🧹"
fclean: clean
	@rm -f ${NAME}
	@echo "🗑️"

re:fclean all
