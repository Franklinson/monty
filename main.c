#include "monty.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	StackNode *stack = NULL;
	char instruction[100];
	int line_number = 1;

	while (fgets(instruction, sizeof(instruction), stdin))
	{
		instruction[strcspn(instruction, "\n")] = '\0';
		char *opcode = strtok(instruction, " \t");
		char *argument = strtok(NULL, " \t");

	if (strcmp(opcode, "push") == 0)
	{
		push(&stack, argument, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		/*Implement the pall opcode here*/
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		/*Implement the pint opcode here*/
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	line_number++;
	}

	while (stack != NULL)
	{
		StackNode *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (0);
}
