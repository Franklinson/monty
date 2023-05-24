#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *file_name = argv[1];
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	char line[100];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		char *opcode = parse_opcode(line);

		if (opcode != NULL)
		{
			opcode_handler(opcode, &stack, line_number);
		}
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
