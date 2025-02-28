#include "./../push_swap.h"

long long	ft_atoi2(char *chNum)
{
	int				i;
	int				k;
	long long int	j;

	i = 0;
	j = 0;
	k = 1;
	while ((chNum[i] < 14 && (chNum[i] > 8)) || chNum[i] == 32)
		i++;
	if (chNum[i] == 45 || chNum[i] == 43)
	{
		if (chNum[i] == 45)
			k = -1;
		i++;
	}
	while (chNum[i] >= '0' && chNum[i] <= '9')
	{
		j = j * 10 + (chNum[i] - '0');
		i++;
	}
	return (j * k);
}

static t_stack	*rec_arg_int(int i, char **argv)
{
	t_stack	*stack;

	if (!argv[i])
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = ft_atoi2(argv[i]);
	stack->next = rec_arg_int(i + 1, argv);
	return (stack);
}

int	stack_order(int i, t_stack **stack)
{
	int		order;
	t_stack	**tmp;

	order = 1;
	tmp = stack;
	while (*tmp)
	{
		if ((*tmp)->data == i)
			return (order);
		(*tmp) = (*tmp)->next;
		order++;
	}
	return (-1);
}

void	arg_int(t_data **data, t_stack **stack)
{
	*stack = rec_arg_int(0, (*data)->arg);
	if (!*stack)
		shut_program_error(stack, data);
	(*data)->stack_size = stack_size(stack);
}

void	push_two(t_stack **a, t_stack **b, t_data **data)
{
	pa_pb(a, b, "pb\n");
	if ((*data)->stack_size != 4)
		pa_pb(a, b, "pb\n");
	(*data)->a_size = stack_size(a);
	(*data)->b_size = stack_size(b);
}
