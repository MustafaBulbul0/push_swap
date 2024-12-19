#include "push_swap.h"

void    push_swap(int *stack_a)
{
    int *stack_b;
    int size;

    stack_b = (int *)ft_calloc((sizeof(stack_a) / 4) + 1, sizeof(int));
    stack_b[(sizeof(stack_a) / 4) + 1] = '\0';
    ft_pa_pb(stack_a, stack_b);
    while (stack_a[0] != 0 || stack_a[1] == 0)
    {
        if(is_smallest(stack_a[0], stack_b))
        {
            while (!is_smallest(stack_b[0], stack_b))
                ft_ra_rb(stack_b);
            ft_pa_pb(stack_a, stack_b);
        }
        if(is_largest(stack_a[0], stack_b))
        {
            while (!is_largest(stack_b[0], stack_b))
                ft_ra_rb(stack_b);
            ft_ra_rb(stack_b);
            ft_pa_pb(stack_a, stack_b);
        }
        size = sizeof(stack_b) / 4;
        while (!((stack_b[0] > stack_a[0]) && (stack_b[size] < stack_a[0])))
            ft_ra_rb(stack_b);
        ft_pa_pb(stack_a, stack_b);
    }
}

int main()
{
    int stack_a[] = {34,65,157,9032,73,1,4,0,123};

    push_swap(stack_a);
}