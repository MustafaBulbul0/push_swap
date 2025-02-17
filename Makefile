NAME = push_swap
CC = cc
RM = rm -rf
CFLAG = -Wall -Wextra -Werror
PRINTF_DIR = ./library/ft_printf
LIBFT_DIR = ./library/libft
UTILS_DIR = ./utils


SRCS = push_swap.c \
		$(UTILS_DIR)/utils_one \
		free.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)


$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)

clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
