#include "monty.h"

/**
 * full_path - The filename with path to use for opening file
 * @path_name: The path location
 * @file_name: The name given by command line
 *
 * Return: no return value
 */
void full_path(char **path_name, char *file_name)
{
	*path_name = malloc(strlen(file_name) + 3);
	if (!*path_name)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(*path_name, "./");
	strcat(*path_name, file_name);
}

