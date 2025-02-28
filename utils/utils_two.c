#include "./../push_swap.h"

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

void	arg_int(t_data **data, t_stack **stack)
{
	*stack = rec_arg_int(0, (*data)->arg);
	if (!*stack)
		shut_program_error(stack, data);
	(*data)->stack_size = stack_size(stack);
}

int	index_num(t_stack **b, int number)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == number)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static int	move_calculator(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a < b)
			a = b;
	}
	else if (a < 0 && b >= 0)
	{
		a = a * (-1);
		a = a + b;
	}
	else if (a >= 0 && b < 0)
	{
		b = b * (-1);
		a = a + b;
	}
	else if (a < 0 && b < 0)
	{
		if (a > b)
			a = b;
		a = a * (-1);
	}
	return (a);
}

int	move_number(t_stack **a, t_stack **b, int num_b, int indexa)
{
	int	indexb;
	int	in_a;
	int	in_b;
	int	move;

	in_a = 0;
	in_b = 0;
	indexb = index_num(b, num_b) - 1;
	if (stack_size(a) / 2 >= indexa)
		in_a = indexa;
	else if (stack_size(a) / 2 < indexa)
		in_a = indexa - stack_size(a);
	if (stack_size(b) / 2 >= indexb)
		in_b = indexb;
	else if (stack_size(b) / 2 < indexb)
		in_b = indexb - stack_size(b);
	move = move_calculator(in_a, in_b);
	return (move);
}
