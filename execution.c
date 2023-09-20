#include "monty.h"
/**
 * execution - Function to execute the commands.
 * @args : Pointer to array used for strtok (to store strings from .m file).
 * @inst_arr : Pointer to array of lines from .m file.
 * @commands : Pointer to array of opcode and command.
 * Return: Void.
 */
void execution(char *args, char **inst_arr, char *commands[])
{
	args = strtok(inst_arr[j], " ");
	commands[0] = args;
	while (args != NULL)
	{
		args = strtok(NULL, " ");
		commands[i] = args;
		i++;
	}
	if (!commands[1] || !atoi(commands[1]))
		fprintf(stderr, "L%d: usage: push integer\n", j),
			exit(EXIT_FAILURE);
	push(&stack, atoi(commands[1]));
	pall(stack);
}
