#include "monty.h"

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the stack
 *
 * Description: Frees all nodes of a stack and sets stack to NULL.
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}
