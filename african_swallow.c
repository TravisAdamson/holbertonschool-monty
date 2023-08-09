#include "monty.h"

/**
 * file_exists - Checks if the file_name is valid
 * @file_name: given file name
 * @line_number: The current line number
 *
 * Return value: No return value
 */
void file_exists(char *path_name, char *file_name)
{
	if (access(path_name, F_OK) == -1  || access(path_name, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free(path_name);
		exit(EXIT_FAILURE);
	}
}

