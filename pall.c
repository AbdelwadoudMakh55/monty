#include "monty.h"
/**
 * pall - prints all the elements of a stack
 * @stack : Pointer to top of stack.
 * Return: Number of elements.
 */
size_t pall(stack_t *stack)
{
	size_t len = 0;

	while (stack != NULL)
	{
		printf("%d\n", (*stack).n);
		len++;
		stack = (*stack).next;
	}
	return (len);
}
