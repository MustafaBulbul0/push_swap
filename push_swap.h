/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:55:04 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 10:45:45 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

void ft_push_swap(int *stack_a ,int stack_size);

void    more_three_value(int *arr, int stack_size);
void    three_value(int *arr);

void	*ft_calloc(size_t arrSize, size_t varSize);
int	same_num_control(int *arr, int const stack_size);

void    ft_sa_sb(int   *swap, int const stack_size);
void    ft_pa_pb(int *from, int *dest, int const stack_size);
void    ft_ra_rb(int *rotate, int const stack_size);
void    ft_rra_rrb(int *rotate, int const stack_size);
void	ft_write(int file,char *text, int size);

#endif
