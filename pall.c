#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @head: Pointer to the head of the stack.
 *
 * Return: Void.
 */
void pall(StackNode *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}
