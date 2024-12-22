/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:22:26 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 09:30:52 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa_sb(int   *swap, int const stack_size)
{
    int temp;

    if (stack_size < 2)
        return ;
    temp = swap[0];
    swap[0] = swap[1];
    swap[1] = temp;
}

void    ft_pa_pb(int *from, int *dest, int const stack_size)
{
    int size;
    int temp;
    int i;

    i = 0;
    size = stack_size;
    temp = from[0];
    while (i + 1 < size)
    {
        from[i] = from[i + 1];
        i++;
    }
    from[size - 1] = 0;
    while (0 != size)
    {
        dest[size] = dest[size - 1];
        size--;
    }
    dest[0] = temp;
}

void    ft_ra_rb(int *rotate, int const stack_size)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    while(!((rotate[i] == 0 && rotate[i + 1] == 0) || i >= stack_size))
        i++;
    temp = rotate[0];
    while(j < i)
    {
        rotate[j] = rotate[j + 1];
        j++;
    }
    rotate[j - 1] = temp;
}

void    ft_rra_rrb(int *rotate, int const stack_size)
{
    int j;
    int i;
    int temp;

    i = 0;
    while(!((rotate[i] == 0 && rotate[i + 1] == 0) || i >= stack_size))
        i++;
    temp = rotate[i - 1];
    while (i > 0)
    {
        i--;
        rotate[i] = rotate[i - 1];
    }
    rotate[0] = temp;
}
