#include "../push_swap.h"

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


void turk_algorithm(t_stack **a, t_data **data)
{
	t_stack	**b;
	
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		shut_program_error(a, data);
	*b = NULL;
	push_two(a, b, data);



	free_list(b);
}
