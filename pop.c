#include "monty.h"
/**
 * pop - deletes the top element.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next_n;

	if (*stack == NULL || stack == NULL)
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number),
			exit(EXIT_FAILURE);
	current = *stack;
	next_n = (*current).next;
	free(current);
	*stack = next_n;
	(**stack).prev = NULL;
}
