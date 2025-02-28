#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	char	**arg;
	int		stack_size;
}	t_data;

void		shut_program_error(t_stack **stack, t_data **data);
void		succes_program(t_stack **stack, t_data **data);
void		free_list(t_stack **stack);
void		main_control(t_data **data);
long long	ft_atoi2(char *chNum);
char		**argv_edit(char **argv, int argc);
void		arg_int(t_data **data, t_stack **a);
void		sa_sb(t_stack **stack, char	*text);
void		pa_pb(t_stack **src, t_stack **dest, char	*text);
void		ra_rb(t_stack **stack, char	*text);
void		rra_rrb(t_stack **stack, char	*text);
void		ss_rr_rrr(int i, t_stack **a, t_stack **b);
void		sort(t_data **data, t_stack **a);
void		sort_3(t_stack **a);
void		turk_algorithm(t_stack **a, t_data **data);
int			find_best_number(t_stack **a, t_stack **b, int min_number);
int			find_location(int number, t_stack **b, int small_num, int big_num);
int			find_location2(int number, t_stack **a, int small_num, int big_num);
void		push_function(t_stack **a, t_stack **b, int num_a, int num_b);
int			stack_size(t_stack **stack);
void		stack_order_control(t_stack **a, t_data **data);
int			index_num(t_stack **b, int number);
int			move_number(t_stack **a, t_stack **b, int num_b, int indexa);

#endif
