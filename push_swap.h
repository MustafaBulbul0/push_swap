#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
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
	char	**arg;
	int 	stack_size;
}	t_data;

void		shut_program_error(t_stack **stack, t_data **data);
void	succes_program(t_stack **stack, t_data **data);
void		main_control(char **argv);
long long	ft_atoi2(char *chNum);
char		**argv_edit(char **argv);
t_stack		**arg_int(t_data **data);
void		sa_sb(t_stack **stack, char	*text);
void		pa_pb(t_stack **src, t_stack **dest, char	*text);
void		ra_rb(t_stack **stack, char	*text);
void		rra_rrb(t_stack **stack, char	*text);
void		ss_rr_rrr(int	i, t_stack **a, t_stack **b);
void		sort_2(t_stack **a);

#endif
