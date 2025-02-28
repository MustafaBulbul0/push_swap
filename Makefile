NAME = push_swap
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
UTILS_DIR = ./utils

SRCS = push_swap.c \
		$(UTILS_DIR)/utils_one.c \
		$(UTILS_DIR)/utils_two.c \
		$(UTILS_DIR)/utils_three.c \
		$(UTILS_DIR)/stack_control.c \
		$(UTILS_DIR)/control_one.c \
		$(UTILS_DIR)/sort.c \
		$(UTILS_DIR)/sort_two.c \
		$(UTILS_DIR)/free.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
