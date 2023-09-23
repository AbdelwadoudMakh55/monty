#include "monty.h"
unsigned int line_number = 0;
/**
 * main - The entry point for the interpreter.
 * @argc : Number of arguments.
 * @argv : Pointer to array of args (char *).
 * Return: 0 Success, 1 else.
 */
int main(int argc, char **argv)
{
	unsigned int i;
	FILE *file;
	char **inst_arr, *args = NULL;

	if (argc == 1 || argc > 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]),
			exit(EXIT_FAILURE);
	inst_arr = malloc(sizeof(char *) * 500);
	if (inst_arr == NULL)
		fprintf(stderr, "Error: malloc failed\n"),
			exit(EXIT_FAILURE);
	while (!feof(file) && !ferror(file))
	{
		inst_arr[line_number] = malloc(sizeof(char) * 200);
		if (inst_arr[line_number] == NULL)
			fprintf(stderr, "Error: malloc failed\n"),
				exit(EXIT_FAILURE);
		if (fgets(inst_arr[line_number], 200, file) != NULL)
			line_number++;
	}
	execution(args, inst_arr, line_number);
	fclose(file);
	for (i = 0; i < line_number; i++)
		free(inst_arr[i]);
	free(inst_arr);
	return (0);
}
