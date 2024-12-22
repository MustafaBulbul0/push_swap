/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:19:53 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 10:45:05 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write(int file,char *text, int size)
{
	write(file ,text, size);
}

void	*ft_calloc(size_t arrSize, size_t varSize)
{
	unsigned char	*t_memory;
	void	*memory;
	size_t	total_size;
	size_t	i;

	i = -1;
	total_size = arrSize * varSize;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	t_memory = (unsigned char *)memory;
	while (++i < total_size)
		t_memory[i] = 0;
	return (memory);
}

int	same_num_control(int *arr,int const stack_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size - 1)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (arr[j] == arr[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
