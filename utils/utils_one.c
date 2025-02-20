#include "./../push_swap.h"

char	**argv_edit(char **argv)
{
	char	**n_argv;
	char	**nn_argv;
	int		i;
	int		n_argv_size;

	n_argv = ft_split((const char *)argv[1], ' ');
	if (!n_argv)
		return (NULL);
	n_argv_size = 0;
	while (n_argv[n_argv_size])
		n_argv_size++;
	nn_argv = (char **)malloc((n_argv_size + 2) * sizeof(char *));
	if (!nn_argv)
		return (free(n_argv), NULL);
	nn_argv[0] = argv[0];
	i = 0;
	while (++i <= n_argv_size)
		nn_argv[i] = ft_strdup(n_argv[i - 1]);
	nn_argv[i] = NULL;
	i = -1;
	while (n_argv[++i])
		free(n_argv[i]);
	free(n_argv);
	return (nn_argv);
}

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

static t_stack	**rec_arg_int(int i, char **argv)
{
	t_stack **new_node;
	if (!argv[i])
		return (NULL);
	new_node = (t_stack **)malloc(sizeof(t_stack *));
	if (!new_node)
		return (NULL);
	*new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!(*new_node))
	{
		free(new_node);
		return (NULL);
	}
	(*new_node)->data = ft_atoi2(argv[i]);
	(*new_node)->next = *rec_arg_int(i + 1, argv);
	return (new_node);
}


t_stack	**arg_int(t_data **data)
{
	t_stack	**stack;
	t_stack	**size;

	stack = rec_arg_int(1, (*data)->arg);
	size = stack;
	(*data)->stack_size = 0;
	while (*size)
	{
		(*size) = (*size)->next;
		(*data)->stack_size++;
	}
	return (stack);
}
