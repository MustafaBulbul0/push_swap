#include "../push_swap.h"

int	max_value(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	min_value(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

static void	push_and_sort(t_stack **a, t_stack **b)
{
	int		num_a;
	int		num_b;

	while (stack_size(a) > 3)
	{
		num_a = find_best_number(a, b, 0);
		num_b = find_location(num_a, b, -2147483648, -2147483648);
		push_function(a, b, num_a, num_b);
		pa_pb(a, b, "pb\n");
	}
	sort_3(a);
	num_a = find_best_number(a, b, 0);
	push_function(a, b, num_a, max_value(b));
}

static void	push_two(t_stack **a, t_stack **b, t_data **data)
{
	pa_pb(a, b, "pb\n");
	if ((*data)->stack_size != 4)
		pa_pb(a, b, "pb\n");
}

void	turk_algorithm(t_stack **a, t_data **data)
{
	t_stack	**b;
	int		num_a;

	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		shut_program_error(a, data);
	*b = NULL;
	push_two(a, b, data);
	push_and_sort(a, b);
	while ((*b))
	{
		num_a = find_location2((*b)->data, a, 2147483647, 2147483647);
		push_function(a, b, num_a, (*b)->data);
		pa_pb(b, a, "pa\n");
	}
	if (index_num(a, min_value(a)) > (stack_size(a) / 2))
		while (min_value(a) != (*a)->data)
			rra_rrb(a, "rra\n");
	else
		while (min_value(a) != (*a)->data)
			ra_rb(a, "ra\n");
	free_list(b);
}
