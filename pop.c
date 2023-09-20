#include "monty.h"
/**
 * pop - deletes the top element.
 * @stack : Pointer to top of stack.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int pop(stack_t **stack)
{
	stack_t *current, *next_n;

	if (*stack == NULL || stack == NULL)
		return (-1);
	current = *stack;
	next_n = (*current).next;
	free(current);
	*stack = next_n;
	(**stack).prev = NULL;
	return (1);
}
