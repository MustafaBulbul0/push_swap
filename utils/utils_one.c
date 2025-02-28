#include "./../push_swap.h"

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
	n_arg = ft_split(c_arg, ' ');
	free(c_arg);
	return (n_arg);
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
