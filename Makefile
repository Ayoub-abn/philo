NAME = philo
CFLAGS = -Wall -Wextra -Werror  -fsanitize=thread -g
# CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
# SRC = main.c philo.c ft_putstr_fd.c ft_atoi.c 
SRC = ${shell find . -type f -name "*.c"}
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

show:
	echo "${SRC}"