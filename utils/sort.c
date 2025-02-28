#include "../push_swap.h"

void	sort(t_data **data, t_stack **a)
{
	if ((*data)->stack_size == 2)
		sort_2(a);
	else if ((*data)->stack_size == 3)
		sort_3(a);
	else if ((*data)->stack_size > 3)
		turk_algorithm(a, data);
}

void	sort_2(t_stack **a)
{
	int	b;
	int	c;

	b = (*a)->data;
	c = (*a)->next->data;
	if (b > c)
		sa_sb(a, "sa\n");
}

void	sort_3(t_stack **a)
{
	int	b;
	int	c;
	int	d;

	b = (*a)->data;
	c = (*a)->next->data;
	d = (*a)->next->next->data;
	if (d > c && d > b && b > c)
		sa_sb(a, "sa\n");
	else if (b > c && b > d && d > c)
		ra_rb(a, "ra\n");
	else if (b > c && b > d && c > d)
	{
		ra_rb(a, "ra\n");
		sa_sb(a, "sa\n");
	}
	else if (c > d && c > b && b > d)
		rra_rrb(a, "rra\n");
	else if (c > d && c > b && d > b)
	{
		rra_rrb(a, "rra\n");
		sa_sb(a, "sa\n");
	}
}

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

void	turk_algorithm(t_stack **a, t_data **data)
{
	t_stack	**b;
	int		num_a;
	int		num_b;

	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		shut_program_error(a, data);
	*b = NULL;
	push_two(a, b, data);
	while (stack_size(a) > 3)
	{
		num_a = find_best_number(a, b);
		num_b = find_location(num_a, b);
		push_function(a, b, num_a, num_b);
		pa_pb(a, b, "pb\n");
	}
	sort_3(a);
	num_a = find_best_number(a, b);
	push_function(a, b, num_a, max_value(b));
	while ((*b))
	{
		num_a = find_location2((*b)->data, a);
		push_function(a, b, num_a, (*b)->data);
		pa_pb(b, a, "pa\n");
	}
	while (min_value(a) != (*a)->data)
		rra_rrb(a, "rra\n");
	free_list(b);
}
