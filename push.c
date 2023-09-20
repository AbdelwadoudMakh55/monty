#include "monty.h"
/**
 * push - adds a new node at the beginning of the stack.
 * @stack : Pointer to Pointer to top of stack..
 * @n : Integer
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *push(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	(*new).n = n;
	if (*stack == NULL)
	{
		(*new).next = NULL;
		(*new).prev = NULL;
		*stack = new;
		return (new);
	}
	(*new).next = *stack;
	(**stack).prev = new;
	(*new).prev = NULL;
	*stack = new;
	return (new);
}
