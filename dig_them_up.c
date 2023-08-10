#include "monty.h"

/**
 * num_args - checks if the correct number of arguments exist
 * @argc: The number of arguments given
 *
 * Return: No return
 */
void num_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

}

/**
 * get_op_code - Find the op code from the next line of file
 * @array: The array
 * @stack: The stack to use
 * @line_number: The current line number
 *
 * Return: No return value
 */
void (*get_op(char **array, unsigned int line_number, stack_t **stack))\
	     (stack_t **stack, unsigned int line_number)
{
	int index = 0;
	instruction_t instruct[] = {
		{"push", push_m},
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"add", add_m},
		{"nop", nop_m},
		{NULL, NULL},
	};

	if (!array)
		return (NULL);
	new_line = get_tokens(array[0], " ");
	if (!new_line || new_line[0][0] == '#')
		return (NULL);
	while (instruct[index].opcode)
	{
		if (!strcmp(instruct[index].opcode, new_line[0]))
		{
			return (instruct[index].f);
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, new_line[0]);
	free(new_line);
	free(*stack);
	exit(EXIT_FAILURE);
}
