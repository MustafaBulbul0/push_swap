#include "./../push_swap.h"

static char	*combine(int size, int argc, char **argv);

char	**argv_edit(char **argv, int argc)
{
	int		i;
	int		size;
	char	*c_arg;
	char	**n_arg;

	if (argc == 2)
	{
		n_arg = ft_split(argv[1], ' ');
		return (n_arg);
	}
	i = 1;
	size = 0;
	while (i < argc)
	{
		size += ft_strlen(argv[i]) + (i < argc - 1);
		i++;
	}
	c_arg = combine(size, argc, argv);
	n_arg = ft_split(c_arg, ' ');
	free(c_arg);
	return (n_arg);
}

static char	*combine(int size, int argc, char **argv)
{
	char	*c_arg;
	int		i;

	c_arg = (char *)malloc(size + 1);
	if (!c_arg)
		return (NULL);
	c_arg[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(c_arg, argv[i], size + 1);
		if (i < argc - 1)
			ft_strlcat(c_arg, " ", size + 1);
		i++;
	}
	return (c_arg);
}

int	stack_size(t_stack **stack)
{
	t_stack	*size;
	int		total_size;

	size = *stack;
	total_size = 0;
	while (size)
	{
		size = size->next;
		total_size++;
	}
	return (total_size);
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

void	stack_order_control(t_stack **a, t_data **data)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return ;
		tmp = tmp->next;
	}
	succes_program(a, data);
}
