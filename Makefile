NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRC = philo.c

OBG = ${SRC:.c=.o}


%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "✅"

all:${NAME}

${NAME}:${OBG}
	@${CC} ${CFLAGS} ${OBG} -o ${NAME}
	@rm -f ${OBG}
	@echo "💯"

# re:fclean all

# clean:
# 	@rm -f ${OBG}
# 	@echo "🧹"
fclean:
	@rm -f ${NAME}
	@echo "🗑️"
