/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:57:55 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/22 02:10:40 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int *two_value(int *arr)
{
    int temp;

    if (arr[0] > arr[1])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    return (arr);
}

int *three_value_continue(int *arr)
{
    int temp;
    
    if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
    {
        temp = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
    }
    else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
    }
    return (arr);
}

int *three_value(int *arr)
{
    int temp;

    if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
    {
        temp = arr[2];
        arr[2] = arr[1];
        arr[1] = temp;
    }
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
    {
        temp = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
    }
    else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
    {
        temp = arr[0];
        arr[0] = arr[2];
        arr[2] = temp;
    }
    else
        arr = three_value_continue(arr);
    return (arr);    
}

void ft_push_swap(int *stack_a)
{
    int size;
    int *stack_b;

    size = sizeof(stack_a) / sizeof(stack_a[0]) - 1;
    if (same_num_control(stack_a))
        return ;
    stack_b = (int *)ft_calloc(size + 1, sizeof(int));
    if (!stack_b)
        return ;
    if (size > 3)
    {
        ;
    }
    else if (size == 3)
        three_value(stack_a);
    else if (size == 2)
        two_value(stack_a);
    free(stack_b);
}

int main()
{
    int arr[] = {2,3,1};
    int *arr2;
    
    ft_push_swap(arr);
    printf("%d ",arr[0]);
    printf("%d ",arr[1]);
    printf("%d \n",arr[2]);
    
}