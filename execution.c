#include "monty.h"
int n = 0;
stack_t *stack = NULL;
/**
 * execution - Function to execute the commands.
 * @args : Pointer to array used for strtok (to store strings from .m file).
 * @inst_arr : Pointer to array of lines from .m file.
 * @commands : Pointer to array of opcode and command.
 * @line_number : Number of lines in .m file.
 * Return: Void.
 */
void execution(char *args, char **inst_arr, char *commands[],
unsigned int line_number)
{
	unsigned int j = 0, i = 1;
	void (*opcode)(stack_t **, unsigned int);

	while (j < line_number)
	{
		i = 1;
		if (strlen(inst_arr[j]) == 1)
			j++;
		else
		{
			inst_arr[j][strlen(inst_arr[j]) - 1] = '\0';
			args = strtok(inst_arr[j], " ");
			commands[0] = args;
			while (args != NULL)
			{
				args = strtok(NULL, " ");
				commands[i] = args;
				i++;
			}
			if (strcmp(commands[0], "pint") == 0 &&
			commands[1] != NULL)
				fprintf(stderr, "L%u: unknown instruction %s\n"
				, line_number, commands[0]),
				exit(EXIT_FAILURE);
			if (strcmp(commands[0], "push") == 0 &&
			(commands[1] == NULL || !atoi(commands[1])))
				fprintf(stderr, "L%u: usage: push integer\n",
				j + 1), exit(EXIT_FAILURE);
			if (strcmp(commands[0], "push") == 0)
				n = atoi(commands[1]);
			opcode = gof(commands[0], j + 1);
			opcode(&stack, j + 1);
			j++;
		}
	}
}
