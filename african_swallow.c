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
	if (access(path_name, F_OK) || access(path_name, R_OK) || !access(path_name, X_OK))
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", file_name);
		free(path_name);
		exit(EXIT_FAILURE);
	}
}

