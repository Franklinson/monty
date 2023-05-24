#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @head: Pointer to the head of the stack.
 * @strval: String representation of the integer value to be pushed.
 * @opcode: Opcode name.
 * @line: Line number in the Monty file.
 * @str: File pointer to the Monty file.
 *
 * Return: Void.
 */
void push(StackNode **head, char *strval, char *opcode, int line, FILE *str)
{
	StackNode *newNode;
	int n;

	if (strval == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	n = atoi(strval);
	if ((strcmp(strval, "0") != 0) && n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(StackNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}
