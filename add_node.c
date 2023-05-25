#include "monty.h"

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
		free_stack(stack);
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
