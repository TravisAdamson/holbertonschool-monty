#include "monty.h"

/**
 * push_m - push the given value to the monty stack
 * @stack: The current stack
 * @line_number: current line number in the file
 *
 * Return: No return
 */
void push_m(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num;

	if (!new_line[1] || (strcmp(new_line[1], "") != 0))
	{
		dprintf(STDOUT_FILENO, "l%d: usage: push integer\n", line_number);
		free(new_line[0]);
		exit(EXIT_FAILURE);
	}
	num = atoi(new_line[1]);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		free(new_line[1]);
		free(new_line[0]);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = *stack;
	new->prev = NULL;

	if (new->next != NULL)
		new->next->prev = new;
	*stack = new;
}

/**
 * pall_m - print the current stack
 * @stack: current stack
 * @line_number: current line number in the file
 *
 * Return: no return value
 */
void pall_m(stack_t **stack, unsigned int line_number)
{
	stack_t *in_stack;
	
	(void)line_number;
	if (!stack)
		return;
	in_stack = *stack;
	while (in_stack)
	{
		printf("%d\n", in_stack->n);
		in_stack = in_stack->next;
	}
}
