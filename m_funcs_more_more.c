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

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul_stack = *stack;
	mul_stack->next->n = mul_stack->next->n * mul_stack->n;
	pop_m(stack, line_number);
}

/**
 * mod_m - Gets the mod value from dividing second by first
 * @stack: The stack to manipulate
 * @line_number: The current line number from file
 *
 * Return: No Return value
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	stack_t *mod_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod_stack = *stack;
	mod_stack->next->n = (mod_stack->next->n) % (mod_stack->n);
	pop_m(stack, line_number);
}
