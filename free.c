#include "push_swap.h"

void	shut_program_error(t_stack *stack, t_data *data)
{
	if (stack);
		free_list(stack);
	if (data)
	{
		free(data->stack_a);
		free(data->stack_b);
	}
	write(2, "Error\n", 6);
	exit(STDERR_FILENO);
}

void free_list(t_stack *node)
{
	t_stack	*temp;

	while (node)
	{
		temp = node;
		node = node->data;
		free(temp);
	}
}
