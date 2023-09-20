#include "monty.h"
/**
 * main - The entry point for the interpreter.
 * @argc : Number of arguments.
 * @argv : Pointer to array of args (char *).
 * Return: 0 Success, 1 else.
 */
stack_t *stack = NULL;
int line_number = 0;
int main(int argc, char **argv)
{
	FILE *file; 
	char *inst_arr[20], *args = NULL, *commands[10] = {0};
	int i = 1, j = 0;

	if (argc == 1 || argc > 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]),
			exit(EXIT_FAILURE);
	while (!feof(file) && !ferror(file))
	{
		inst_arr[line_number] = malloc(sizeof(char) * 50);
		if (inst_arr[line_number] == NULL)
			fprintf(stderr, "Error: malloc failed\n"), 
				exit(EXIT_FAILURE);
		if (fgets(inst_arr[line_number], 50, file) != NULL)
			line_number++;
	}
	/*args = strtok(inst_arr[j], " ");
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
	fclose(file);*/
	return (0);
}
