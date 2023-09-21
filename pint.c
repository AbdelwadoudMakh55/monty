#include "monty.h"
/**
 * pint - prints the top of the stack.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (len_stack(stack) == 0)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number),
			exit(EXIT_FAILURE);
	printf("%d\n", (**stack).n);
}
