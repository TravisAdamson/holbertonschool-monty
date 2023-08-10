#include "monty.h"
/**
 * num_only - Makes sure the arguement is only a number
 * @in_arg: The number to verify
 *
 * Return: 1 if all numbers, 0 if not
 */
int num_only(char *in_arg)
{
	int index = 0;

	while (in_arg[index])
	{
		if (in_arg[index] < 48 || in_arg[index] > 57)
		{
			if (in_arg[index] != '-')
				return (1);
		}
		index++;
	}
	return (0);
}
/**
 * push_m - push the given value to the monty stack
 * @stack: The current stack
 * @line_number: current line number in the file
 *
 * Return: No return
 */
void push_m(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int num;

	if (!new_line[1] || !strcmp(new_line[1], "") || num_only(new_line[1]) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_line[0]);
		new_line[0] = strdup("FATAL_PUSH_ERROR");
		return;
	}
	num = atoi(new_line[1]);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

/**
 * pint_m - print the current top of the stack
 * @stack: current stack
 * @line_number: current line number in the file
 *
 * Return: no return value
 */
void pint_m(stack_t **stack, unsigned int line_number)
{
        stack_t *in_stack;

        if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	in_stack = *stack;
        while (in_stack->prev != NULL)
        {
		in_stack = in_stack->prev;
        }
	printf("%d\n", in_stack->n);
}
