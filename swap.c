#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack : pointer to top of stack.
 * Return: Void.
 */
void swap(stack_t **stack)
{
	stack_t *tmp, *thrd_top;

	tmp = *stack;
	*stack = (**stack).next;
	thrd_top = (**stack).next;
	(**stack).prev = NULL;
	(**stack).next = tmp;
	(*tmp).next = thrd_top;
	(*tmp).prev = *stack;
	(*thrd_top).prev = tmp;
}
