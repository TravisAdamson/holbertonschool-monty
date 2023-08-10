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

/**
 * add_m - Adds the top two nodes
 * @stack: The stack to work in
 * @line_number: The current line_number
 *
 * Return: No return value
 */
void add_m(stack_t **stack, unsigned int line_number)
{
	stack_t *add_stack;
	int total = 0;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_stack = *stack;
	if (add_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = add_stack->next;
	total = add_stack->n;
	total = total + add_stack->next->n;
	add_stack->next->n = total;
	add_stack->next->prev = NULL;
	free(add_stack);
}
