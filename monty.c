#include "monty.h"

/**
 * main - My monty file interpreter
 * @argc: The number of arguments 
 * @argv: The arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *path_name, *file_name;

	new_line = NULL;
	path_name = NULL;
	file_name = NULL;

	num_args(argc);
	file_name = argv[1];
	full_path(&path_name, file_name);
	file_exists(path_name, file_name);
	printf("Getting here");
	fflush(stdout);
	parse_file(path_name);
	exit(EXIT_SUCCESS);
}

