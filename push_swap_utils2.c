#include "push_swap.h"

int	ft_atoi(const char *chNum)
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

void	*ft_calloc(size_t arrSize, size_t varSize)
{
	unsigned char	*t_memory;
	void	*memory;
	size_t	total_size;
	size_t	i;

	i = -1;
	t_memory = (unsigned char *)memory;
	total_size = arrSize * varSize;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	while (++i < varSize)
		t_memory[i] = 0;
	return (memory);
}

int	is_smallest(int	num, int *arr)
{
	int	size;

	size = sizeof(arr) / 4;
	while (--size >= 0)
	{
		if(arr[size] < num)
			return (0);
	}
	return (1);
}

int	is_largest(int	num, int *arr)
{
	int	size;

	size = sizeof(arr) / 4;
	while (--size >= 0)
	{
		if(arr[size] > num)
			return (0);
	}
	return (1);
}