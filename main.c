#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @ac: Argument count
 * @av: Array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *f;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int ln = 0;
	stack_t *s = NULL;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(av[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, f) != -1)
	{
		ln++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		int i;
		for (i = 0; ops[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, ops[i].opcode) == 0)
			{
				ops[i].f(&s, ln);
				break;
			}
		}

		if (ops[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
			free(line);
			fclose(f);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(f);
	exit(EXIT_SUCCESS);
}
