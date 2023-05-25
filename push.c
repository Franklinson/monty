#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
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
 * is_number - Checks if a string is a valid number
 * @str: String to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * add_node - Adds a new node at the beginning of a stack
 * @stack: Double pointer to the stack
 * @n: Value to be stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	if (stack == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}
