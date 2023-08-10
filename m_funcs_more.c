#include "monty.h"

/**
 * swap_m - Swaps the top two elements
 * @stack: The stack to swap in
 * @line_number: The existing line number
 *
 * Return: No return value
 */
void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *swap_stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap_stack = *stack;
	if (swap_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap_stack->prev = swap_stack->next;
	swap_stack->next = swap_stack->prev->next;
	swap_stack->prev->prev = NULL;
	swap_stack->prev->next = swap_stack;

	*stack = swap_stack->prev;
}
