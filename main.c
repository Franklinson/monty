#define _POSIX_C_SOURCE 200810L
#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			char *value = strtok(NULL, " \t\n");

			if (value == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free_stack(&stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(value));
		}
		else
		{
			void (*instruction)(stack_t **, unsigned int) = get_instruction(opcode);

			if (instruction == NULL)
				{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free_stack(&stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			instruction(&stack, line_number);
		}
	}

	free_stack(&stack);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
