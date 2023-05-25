#include "monty.h"

/**
 * get_instruction - Retrieves the function associated with an opcode
 * @opcode: The opcode to search for
 *
 * Return: Pointer to the function associated with the opcode,
 *         or NULL if the opcode is not found
 */
void (*get_instruction(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		/* Add more instructions here as needed */
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
