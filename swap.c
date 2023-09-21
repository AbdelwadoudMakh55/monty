#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack : pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *thrd_top;

	if (len_stack(stack) < 2)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number),
			exit(EXIT_FAILURE);
	tmp = *stack;
	*stack = (**stack).next;
	thrd_top = (**stack).next;
	(**stack).prev = NULL;
	(**stack).next = tmp;
	(*tmp).next = thrd_top;
	(*tmp).prev = *stack;
	(*thrd_top).prev = tmp;
}
