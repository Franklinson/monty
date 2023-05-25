#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * is_integer - checks if a string is a valid integer
 * @str: string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
