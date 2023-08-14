#include "monty.h"
/**
 * mul_m - Multiplies the top two elements
 * @stack: The stack to manipulate
 * @line_number: The current line number from file
 *
 * Return: No return value
 */
void mul_m(stack_t **stack, unsigned int line_number)
{
	stack_t *mul_stack;

	if (*stack != NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul_stack = *stack;
	mul_stack->next->n = mul_stack->next->n * mul_stack->n;
	pop_m(stack, line_number);
}
