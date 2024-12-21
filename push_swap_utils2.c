/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:19:53 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 02:40:41 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	same_num_control(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[j] == arr[i])
				return (1);
			j++;
		}
	}
	return (0);
}

int get_size(int *arr)
{
    int size = 0;
    while (arr[size] != 2147483647)
        size++;
    return size;
}
