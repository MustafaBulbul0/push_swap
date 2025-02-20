#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	**a;
	//t_stack	**b;
	t_data	**data;

	if (argc <= 1)
		shut_program_error(NULL, NULL);
	if (argc == 2)
		argv = argv_edit(argv);
	main_control(argv);
	a = (t_stack **)malloc(sizeof(t_stack *));
	//b = (t_stack **)malloc(sizeof(t_stack *));
	data = (t_data **)malloc(sizeof(t_data *));
	if (!a || !data)
		shut_program_error(NULL, NULL);
	*data = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		shut_program_error(NULL, NULL);
	(*data)->arg = argv;
	a = arg_int(data);
	if ((*data)->stack_size == 2)
		sort_2(a);
	printf("%d\n", (*a)->data);
	printf("%d\n", (*a)->next->data);

	free(argv);
}
