#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "./library/libft/libft.h"
#include "./library/ft_printf/ft_printf.h"

typedef	struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int 	stack_size;
}	t_data;

void		shut_program_error(t_stack *stack, t_data *data);
void		main_control(char **argv);
long long	ft_atoi2(const char *chNum);

#endif
