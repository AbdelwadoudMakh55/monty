#include "monty.h"
/**
 * execution - Function to execute the commands.
 * @args : Pointer to array used for strtok (to store strings from .m file).
 * @inst_arr : Pointer to array of lines from .m file.
 * @commands : Pointer to array of opcode and command.
 * @line_number : Number of lines in .m file.
 * @stack : Pointer to stack top.
 * Return: Void.
 */
void execution(char *args, char **inst_arr, char *commands[], int line_number,
		stack_t *stack)
{
	int j = 0, i = 1;

	while (j < line_number)
	{
		i = 1;
		inst_arr[j][strlen(inst_arr[j]) - 1] = '\0';
		args = strtok(inst_arr[j], " ");
		commands[0] = args;
		while (i < 2)
		{
			args = strtok(NULL, " ");
			commands[i] = args;
			i++;
		}
		if ((strcmp(commands[0], "push") == 0) &&
		(!commands[1] || !atoi(commands[1])))
			fprintf(stderr, "L%d: usage: push integer\n", j),
				exit(EXIT_FAILURE);
		if (strcmp(commands[0], "push") == 0)
			push(&stack, atoi(commands[1]));
		if (strcmp(commands[0], "pall") == 0)
			pall(stack);
		if (strcmp(commands[0], "pint") == 0)
		{
			if (len_stack(stack) == 0)
				fprintf(stderr, "L%d: can't pint, stack empty\n", j),
					exit(EXIT_FAILURE);
			printf("%d\n", (*stack).n);
		}
		if (strcmp(commands[0], "pop") == 0)
			pop(&stack);
		if (strcmp(commands[0], "nop") == 0)
			return;
		if (strcmp(commands[0], "swap") == 0)
			swap(&stack);
		j++;
	}
}
