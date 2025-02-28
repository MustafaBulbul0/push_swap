#include "../push_swap.h"

static void	control_one(t_data **data);
static void	control_two(t_data **data);
static void	control_three(t_data **data);

void	main_control(t_data **data)
{
	control_one(data);
	control_two(data);
	control_three(data);
}

static void	control_one(t_data **data)
{
	char	**argv;
	int		size;
	int		i;
	int		j;

	argv = (*data)->arg;
	i = 0;
	while (argv[i])
	{
		j = 0;
		size = ft_strlen(argv[i]);
		if (size <= 0)
			shut_program_error(NULL, data);
		else if ((size >= 1) && (argv[i][j] == '-' || argv[i][j] == '+'))
			if (!(argv[i][++j] >= '0' && argv[i][j] <= '9'))
				shut_program_error(NULL, data);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				shut_program_error(NULL, data);
			j++;
		}
		i++;
	}
}

static void	control_two(t_data **data)
{
	char		**argv;
	long long	number;
	long long	int_min;
	long long	int_max;
	int			i;

	argv = (*data)->arg;
	i = 0;
	int_max = __INT_MAX__;
	int_min = (int_max) * (-1) - 1;
	while (argv[i])
	{
		number = ft_atoi2(argv[i]);
		if (!(number <= int_max && number >= int_min))
			shut_program_error(NULL, data);
		i++;
	}
}

static void	check_duplicates(int *values, int size, t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
			{
				free(values);
				shut_program_error(NULL, data);
			}
			j++;
		}
		i++;
	}
}

static void	control_three(t_data **data)
{
	char	**argv;
	int		*values;
	int		i;
	int		size;

	argv = (*data)->arg;
	size = 0;
	while (argv[size])
		size++;
	values = malloc(sizeof(int) * size);
	if (!values)
		shut_program_error(NULL, data);
	i = 0;
	while (i < size)
	{
		values[i] = ft_atoi2(argv[i]);
		i++;
	}
	check_duplicates(values, size, data);
	free(values);
}
