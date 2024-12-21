/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:55:04 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 02:42:32 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

void ft_push_swap(int *stack_a);
void	*ft_calloc(size_t arrSize, size_t varSize);
int *three_value(int *arr);
int	same_num_control(int *arr);
int get_size(int *arr);

#endif

