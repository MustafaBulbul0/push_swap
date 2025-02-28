NAME = push_swap
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
PRINTF_DIR = ./library/ft_printf
LIBFT_DIR = ./library/libft
UTILS_DIR = ./utils

SRCS = push_swap.c \
		$(UTILS_DIR)/utils_one.c \
		$(UTILS_DIR)/utils_two.c \
		$(UTILS_DIR)/utils_three.c \
		$(UTILS_DIR)/stack_control.c \
		$(UTILS_DIR)/control_one.c \
		$(UTILS_DIR)/sort.c \
		$(UTILS_DIR)/free.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
