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

	if (!stack || !*stack)
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

/**
 * nop_m - Does nothing
 * @stack: The stack to do nothing to
 * @line_number: The line number requesting nothing to be done
 *
 * Return: No return
 */
void nop_m(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_m - Subtract the top element from the next one down
 * @stack: The stack to be used
 * @line_number: The current line number from the file
 *
 * Return: No Return value
 */
void sub_m(stack_t **stack, unsigned int line_number)
{
	stack_t *sub_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub_stack = *stack;
	sub_stack->next->n = sub_stack->next->n - sub_stack->n;
	pop_m(stack, line_number);
}

/**
 * div_m - Divides the second element by the first
 * @stack: The stack to be used
 * @line_number: The current line number from the file
 *
 * Return: No Retun Value
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	stack_t *div_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_SUCCESS);
	}
	div_stack = *stack;
	div_stack->next->n = div_stack->next->n / div_stack->n;
	pop_m(stack, line_number);
}
