#include "../push_swap.h"

void	sa_sb(t_stack **stack)
{
	t_stack *first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;

	first = *stack;
	*stack = first->next->next;
	first->next->next = NULL;
	second = first->next;
	first->next = NULL;
	second->next = first;
	second->next->next = *stack;
	*stack = second;
}

void	pa_pb(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
}

void	ra_rb(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rra_rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = *stack;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	if (temp)
		temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ss_rr_rrr(int	i, t_stack **a, t_stack **b)
{
	if (i == 1)
	{
		sa_sb(a);
		sa_sb(b);
	}
	else if (i == 2)
	{
		ra_rb(a);
		ra_rb(b);
	}
	else if (i == 3)
	{
		rra_rrb(a);
		rra_rrb(b);
	}
}
