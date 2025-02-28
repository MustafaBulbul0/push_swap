#include "../push_swap.h"

int	find_location(int number, t_stack **b, int small_num, int big_num)
{
	int		min;
	t_stack	*tmp;

	min = 0;
	tmp = *b;
	while (tmp)
	{
		if (number > tmp->data)
		{
			if (small_num < tmp->data)
			{
				small_num = tmp->data;
				min++;
			}
		}
		else
		{
			if (big_num < tmp->data)
				big_num = tmp->data;
		}
		tmp = tmp->next;
	}
	if (min > 0)
		return (small_num);
	return (big_num);
}

int	find_location2(int number, t_stack **a, int small_num, int big_num)
{
	int		min;
	t_stack	*tmp;

	min = 0;
	tmp = *a;
	while (tmp)
	{
		if (number < tmp->data)
		{
			if (small_num > tmp->data)
			{
				small_num = tmp->data;
				min++;
			}
		}
		else
		{
			if (big_num > tmp->data)
				big_num = tmp->data;
		}
		tmp = tmp->next;
	}
	if (min > 0)
		return (small_num);
	return (big_num);
}

int	find_best_number(t_stack **c, t_stack **d, int min_number)
{
	t_stack	*tmp_a;
	int		min_move;
	int		move;
	int		index;
	int		num_b;

	tmp_a = *c;
	min_move = 2147483647;
	index = 0;
	while (tmp_a)
	{
		num_b = find_location(tmp_a->data, d, -2147483648, -2147483648);
		move = move_number(c, d, num_b, index);
		if (move < min_move)
		{
			min_move = move;
			min_number = tmp_a->data;
		}
		index++;
		tmp_a = tmp_a->next;
	}
	return (min_number);
}

static void	rotate(int size, int index, int how, t_stack **a)
{
	if (how == 1)
	{
		if (size / 2 >= index)
			ra_rb(a, "ra\n");
		else
			rra_rrb(a, "rra\n");
	}
	else if (how == 2)
	{
		if (size / 2 >= index)
			ra_rb(a, "rb\n");
		else
			rra_rrb(a, "rrb\n");
	}
}

void	push_function(t_stack **a, t_stack **b, int num_a, int num_b)
{
	int	in_a;
	int	in_b;
	int	size_a;
	int	size_b;

	in_a = index_num(a, num_a);
	in_b = index_num(b, num_b);
	if (!(*a) || !(*b) || in_a == -1 || in_b == -1)
		return ;
	while ((*a)->data != num_a || (*b)->data != num_b)
	{
		size_a = stack_size(a);
		size_b = stack_size(b);
		if (size_a / 2 >= in_a && size_b / 2 >= in_b
			&& (*b)->data != num_b && (*a)->data != num_a)
			ss_rr_rrr(2, a, b);
		else if (size_a / 2 < in_a && size_b / 2 < in_b
			&& (*b)->data != num_b && (*a)->data != num_a)
			ss_rr_rrr(3, a, b);
		else if ((*a)->data != num_a)
			rotate(size_a, in_a, 1, a);
		else if ((*b)->data != num_b)
			rotate(size_b, in_b, 2, b);
	}
}
