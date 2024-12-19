#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
#include <unistd.h>

void    push_swap(int *stack_a);
void    ft_sa_sb(int   *swap);
void    ft_pa_pb(int *from, int *dest);
void    ft_ra_rb(int *rotate);
void    ft_rra_rrb(int *rotate);
int	    ft_atoi(const char *chNum);
void	*ft_calloc(size_t arrSize, size_t varSize);
int	is_smallest(int	num, int *arr);
int	is_largest(int	num, int *arr);

#endif