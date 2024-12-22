/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:57:55 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 11:37:24 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    two_value(int *arr)
{
    int temp;

    if (arr[0] > arr[1])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
}

void    three_value_continue(int *arr)
{
    int temp;
    
    if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
    {
        temp = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
        ft_write(1, "sa\n", 3);
    }
    else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
    {
        temp = arr[0];
        arr[0] = arr[2];
        arr[2] = temp;
        ft_write(1, "sa\nrra\n", 6);
    }
    else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
        ft_write(1, "rra\n", 4);
    }
}

void    three_value(int *arr)
{
    int temp;

    if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
    {
        temp = arr[2];
        arr[2] = arr[1];
        arr[1] = temp;
        ft_write(1, "sa\nra\n",6);
    }
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
    {
        temp = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
        ft_write(1, "ra\n", 4);
    }
    else
        three_value_continue(arr); 
}

void ft_push_swap(int *stack_a ,int stack_size)
{
    int *stack_b;

    if (same_num_control(stack_a, stack_size))
        return ;
    stack_b = (int *)ft_calloc(stack_size + 1, sizeof(int));
    if (!stack_b)
        return ;
    if (stack_size > 3)
    {
        more_three_value(stack_a, stack_size);
    }
    else if (stack_size == 3)
        three_value(stack_a);
    else if (stack_size == 2)
        two_value(stack_a);
    free(stack_b);
}

int main()
{
    int arr[] = {1,2,3};
    
    static int const stack_size = 3;
    
    ft_push_swap(arr, stack_size);
    printf("%d ",arr[0]);
    printf("%d ",arr[1]);
    printf("%d \n",arr[2]);
    
}