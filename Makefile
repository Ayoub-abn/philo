NAME = philo
CFLAGS = -Wall -Wextra -Werror  -fsanitize=thread -g 
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRC = main.c philo.c ft_putstr_fd.c ft_atoi.c \

OBG = ${SRC:.c=.o}

%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "✅"

all:${NAME}

${NAME}:${OBG}
	@${CC} ${CFLAGS} ${OBG} -o ${NAME}
	@rm -f ${OBG}
	@echo "💯"


# clean:
# 	@rm -f ${OBG}
# 	@echo "🧹"
fclean:
	@rm -f ${NAME}
	@echo "🗑️"

re:fclean all