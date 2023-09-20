#include "monty.h"
/**
 * add - add the top 2 element.
 * @stack : Pointer to top of stack.
 * Return: Void.
 */
void add(stack_t **stack)
{
	stack_t *next_n;

	if (*stack == NULL || stack == NULL)
		return;
	next_n = (**stack).next;
	(*next_n).n += (**stack).n;
	pop(stack);
}
