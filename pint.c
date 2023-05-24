#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @line: Line number in the Monty file.
 *
 * Return: Void.
 */
void pint(StackNode *head, int line)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->data);
}
