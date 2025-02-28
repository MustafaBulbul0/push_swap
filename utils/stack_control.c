#include "../push_swap.h"

void	sa_sb(t_stack **stack, char	*text)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (text)
		write (1, text, ft_strlen(text));
}

void	pa_pb(t_stack **src, t_stack **dest, char	*text)
{
	t_stack	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
	if (text)
		write (1, text, ft_strlen(text));
}

void	ra_rb(t_stack **stack, char	*text)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	if (text)
		write (1, text, ft_strlen(text));
}

void	rra_rrb(t_stack **stack, char	*text)
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
	if (text)
		write (1, text, ft_strlen(text));
}

void	ss_rr_rrr(int i, t_stack **a, t_stack **b)
{
	if (i == 1)
	{
		sa_sb(a, NULL);
		sa_sb(b, NULL);
		write(1, "ss\n", 3);
	}
	else if (i == 2)
	{
		ra_rb(a, NULL);
		ra_rb(b, NULL);
		write(1, "rr\n", 3);
	}
	else if (i == 3)
	{
		rra_rrb(a, NULL);
		rra_rrb(b, NULL);
		write(1, "rrr\n", 4);
	}
}
