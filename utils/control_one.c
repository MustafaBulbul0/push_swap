#include "../push_swap.h"

static void control_one(t_data **data);
static void	control_two(t_data **data);

void	main_control(t_data **data)
{
	control_one(data);
	control_two(data);
}

static void control_one(t_data **data)
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
		else if((size >= 1) && (argv[i][j] == '-' || argv[i][j] == '+'))
			j++;
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
		if (!(number <= int_max && number >= (int_min)))
			shut_program_error(NULL, data);
		i++;
	}
	
}
