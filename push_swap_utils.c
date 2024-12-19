#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
        Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
        Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
        Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
        Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
        The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
        The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
        The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
        The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

void    ft_sa_sb(int   *swap)
{
    int temp;

    temp = swap[0];
    swap[0] = swap[1];
    swap[1] = temp;
}

void    ft_pa_pb(int *from, int *dest)
{
    int size;
    int temp;
    int i;

    i = -1;
    size = sizeof(from) / 4;
    temp = from[0];
    while (++i + 1 == size)
        from[i] = from[i + 1];
    from[size] = 0;
}

void    ft_ra_rb(int *rotate)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    while(rotate[i] == 0 && rotate[i + 1] == 0)
        i++;
    temp = rotate[0];
    while(j < i - 1)
    {
        rotate[j] = rotate[j + 1];
        j++;
    }
    rotate[j + 1] = temp;
}

void    ft_rra_rrb(int *rotate)
{
    int j;
    int i;
    int temp;

    i = 0;
    while(rotate[i] == 0 && rotate[i + 1] == 0)
        i++;
    temp = rotate[i - 1];
    while (i > 0)
    {
        i--;
        rotate[i] = rotate[i - 1];
    }
    rotate[0] = temp;
}
