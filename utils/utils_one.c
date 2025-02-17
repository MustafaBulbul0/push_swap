#include "./../push_swap.h"

long long	ft_atoi2(char *chNum)
{
	int				i;
	int				k;
	long long int	j;

	i = 0;
	j = 0;
	k = 1;
	while ((chNum[i] < 14 && (chNum[i] > 8)) || chNum[i] == 32)
		i++;
	if (chNum[i] == 45 || chNum[i] == 43)
	{
		if (chNum[i] == 45)
			k = -1;
		i++;
	}
	while (chNum[i] >= '0' && chNum[i] <= '9')
	{
		j = j * 10 + (chNum[i] - '0');
		i++;
	}
	return (j * k);
}

static t_stack	*rec_arg_int(int i, char **argv)
{
	t_stack *new_node;
	if (!argv[i])
		return (NULL);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = ft_atoi2(argv[i]);
	new_node->next = rec_arg_int(i + 1, argv);
	return (new_node);
}

t_stack	*arg_int(char **argv)
{
	t_stack	*stack;

	stack = rec_arg_int(1, argv);
	return (stack);
}
