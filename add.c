#include "monty.h"
/**
 * add - add the top 2 element.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next_n;

	if (len_stack(stack) < 2)
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number), exit(EXIT_FAILURE);
	next_n = (**stack).next;
	(*next_n).n += (**stack).n;
	pop(stack, line_number);
}
