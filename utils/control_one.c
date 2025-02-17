#include "../push_swap.h"

static void control_one(char **argv);
static void	control_two(char **argv);

void	main_control(char **argv)
{
	control_one(argv);
	control_two(argv);
}

static void control_one(char **argv)
{
	int	size;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		size = ft_strlen(argv[i]);
		if (size <= 0)
			shut_program_error(NULL, NULL);
		else if((size >= 1) && (argv[i][j] == '-' || argv[i][j] == '+'))
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				shut_program_error(NULL, NULL);
			j++;
		}
		i++;
	}
}

static void	control_two(char **argv)
{
	long long	number;
	long long	int_min;
	long long	int_max;
	int			i;

	i = 1;
	int_max = __INT_MAX__;
	int_min = (int_max) * (-1) - 1;
	while (argv[i])
	{
		number = ft_atoi2(argv[i]);
		if (!(number <= int_max && number >= (int_min)))
			shut_program_error(NULL, NULL);
		i++;
	}
	
}
