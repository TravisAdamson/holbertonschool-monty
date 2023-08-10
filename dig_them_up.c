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
void (*get_op(char **ar, unsigned int l_n, stack_t **st))(stack_t **st, unsigned int l_n)
{
	int index = 0;
	instruction_t instruct[] = {
		{"push", push_m},
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{NULL, NULL},
	};

	if (!ar)
		return (NULL);
	new_line = get_tokens(ar[0], " ");
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
	fprintf(stderr, "L%d: unknown instruction %s\n", l_n, new_line[0]);
	free(new_line);
	free(*st);
	exit(EXIT_FAILURE);
}
