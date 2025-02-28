#include "../push_swap.h"

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

int	move_calculator(int a, int b)
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

int	find_location(int number, t_stack **b)
{
	int		min;
	int		small_num;
	int		big_num;
	t_stack	*tmp;

	min = 0;
	small_num = -2147483648;
	big_num = -2147483648;
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

int	find_location2(int number, t_stack **a)
{
	int		min;
	int		small_num;
	int		big_num;
	t_stack	*tmp;

	min = 0;
	small_num = 2147483647;
	big_num = 2147483647;
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

int	find_best_number(t_stack **c, t_stack **d)
{
	t_stack	*tmp_a;
	int		min_move;
	int		move;
	int		min_number;
	int		index;
	int		num_b;

	tmp_a = *c;
	min_move = 2147483647;
	min_number = 0;
	index = 0;
	while (tmp_a)
	{
		num_b = find_location(tmp_a->data, d);
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
		{
			if (size_a / 2 >= in_a)
				ra_rb(a, "ra\n");
			else
				rra_rrb(a, "rra\n");
		}
		else if ((*b)->data != num_b)
		{
			if (size_b / 2 >= in_b)
				ra_rb(b, "rb\n");
			else
				rra_rrb(b, "rrb\n");
		}
	}
}
