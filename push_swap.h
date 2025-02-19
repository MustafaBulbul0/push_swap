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
long long	ft_atoi2(char *chNum);
void		sa_sb(t_stack **stack);
void		pa_pb(t_stack **src, t_stack **dest);
void		ra_rb(t_stack **stack);
void		rra_rrb(t_stack **stack);
void		ss_rr_rrr(int	i, t_stack **a, t_stack **b);

#endif
