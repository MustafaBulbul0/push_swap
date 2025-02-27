#include "./../push_swap.h"

char	**argv_edit(char **argv, int argc)
{
	int		i;
	int		size;
	char	*c_arg;
	char	**n_arg;

	if (argc == 2)
	{
		n_arg = ft_split(argv[1], ' ');
		return (n_arg);
	}
	i = 1;
	size = 0;
	while (i < argc)
	{
		size += ft_strlen(argv[i]) + (i < argc - 1);
		i++;
	}
	c_arg = (char *)malloc(size + 1);
	if (!c_arg)
		return (NULL);
	c_arg[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(c_arg, argv[i], size + 1);
		if (i < argc - 1)
			ft_strlcat(c_arg, " ", size + 1);
		i++;
	}
	n_arg = ft_split(c_arg, ' ');
	free(c_arg);
	return (n_arg);
}

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

int	stack_size(t_stack **stack)
{
	t_stack	*size;
	int		total_size;

	size = *stack;
	total_size = 0;
	while (size)
	{
		size = size->next;
		total_size++;
	}
	return (total_size);

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
	pa_pb(a, b, "pb\n");
	if ((*b)->data > (*b)->next->data)
	{
		(*data)->b_max = (*b)->data;
		(*data)->b_min = (*b)->next->data;
	}
	(*data)->a_size = stack_size(a);
	(*data)->b_size = stack_size(b);
}
