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
