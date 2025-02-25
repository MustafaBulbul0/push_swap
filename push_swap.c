#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	**a;
	t_data	**data;

	if (argc <= 1)
		shut_program_error(NULL, NULL);
	data = (t_data **)malloc(sizeof(t_data *));
	if (!data)
		shut_program_error(NULL, NULL);
	*data = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		shut_program_error(NULL, NULL);
	(*data)->arg = argv_edit(argv, argc);
	if (!(*data)->arg || !*((*data)->arg))
		shut_program_error(NULL, NULL);	
	main_control(data);
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a)
		shut_program_error(a, data);
	arg_int(data, a);
	if ((*data)->stack_size == 2)
		sort_2(a);
	if ((*data)->stack_size == 3)
		sort_3(a);
	//printf("%d\n", (*a)->data);
	//printf("%d\n", (*a)->next->data);
	//printf("%d\n", (*a)->next->next->data);
	succes_program(a, data);
}
