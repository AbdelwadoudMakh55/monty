#include "monty.h"
/**
 * main - The entry point for the interpreter.
 * @argc : Number of arguments.
 * @argv : Pointer to array of args (char *).
 * Return: 0 Success, 1 else.
 */
int main(int argc, char **argv)
{
	FILE *file; 
	char *inst_arr[20];
	int line_number = 0, i;

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
	fclose(file);
	return (0);
}
