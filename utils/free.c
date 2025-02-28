#include "../push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}

void	free_data(t_data **data)
{
	int	i;

	if (!data || !*data)
		return ;
	if ((*data)->arg)
	{
		i = 0;
		while ((*data)->arg[i])
		{
			free((*data)->arg[i]);
			i++;
		}
		free((*data)->arg);
	}
	free(*data);
	free(data);
}

void	shut_program_error(t_stack **stack, t_data **data)
{
	if (stack && *stack)
		free_list(stack);
	if (data && *data)
		free_data(data);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	succes_program(t_stack **stack, t_data **data)
{
	if (stack && *stack)
		free_list(stack);
	if (data && *data)
		free_data(data);
	exit (EXIT_SUCCESS);
}
