#include "monty.h"

/**
 * free_array - Free the given array
 * @array: The array to free
 *
 * Return: No return value
 */
void free_array(char **array)
{
	int index = 0;

	if (array == NULL)
		return;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

/**
 * free_stack - Frees the given stack
 * @stack: The stack to free
 *
 * Return: No return
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	if (!stack)
		return;
	while (1)
	{
		temp = stack->next;
		free(stack);
		if (!temp)
			return;
		stack = temp->next;
		free(temp);
		if (!stack)
			return;
	}
}
