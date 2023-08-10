#include "monty.h"

/**
 * get_tokens - Gets the tokens from the line in file
 * @str: The string to use
 * @delim: The Deliminator to use
 *
 * Return: The array generated
 */
char **get_tokens(char *str, char *delim)
{
	int index = 0;
	char *str1 = NULL, *str2 = NULL, *ptr = NULL, **array_to_use = NULL;

	if (!(str) || !(delim))
		return (NULL);
	str1 = strdup(str);
	str2 = strdup(str);
	if (!(str1) || !(str2))
		return (NULL);
	ptr = strtok(str1, delim);
	if (ptr == NULL)
	{
		free(str1);
		free(str2);
		return (NULL);
	}
	for (index = 0; ptr != NULL; index++)
	{
		ptr = strtok(NULL, delim);
	}
	array_to_use = malloc(sizeof(char *) * (index + 1));
	if (array_to_use == NULL)
		return (NULL);
	ptr = strtok(str2, delim);
	if (ptr == NULL)
	{
		free(str1);
		free(str2);
		return (NULL);
	}
	for (index = 0; ptr != NULL; index++)
	{
		array_to_use[index] = strdup(ptr);
		ptr = strtok(NULL, delim);
	}
	array_to_use[index] = NULL;
	free(str1);
	free(str2);
	return (array_to_use);
}

/**
 * parse_file - Reads each file line does stuff
 * @path_name: The name of the path/file combined
 *
 * Return: No Return
 */
void parse_file(char *path_name)
{
	FILE *file_pointer = NULL;
	size_t total = 0;
	char *current_line = NULL, **this_array;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	file_pointer = fopen(path_name, "r");
	if (!file_pointer)
		file_exists(path_name, "");
	free(path_name);
	while (1)
	{
		if ((getline(&current_line, &total, file_pointer)) == -1)
			break;
		if (current_line)
		{
			this_array = get_tokens(current_line, "\n");
			free(current_line), current_line = NULL;
		}
		if (this_array)
		{
			func = get_op(this_array, line_number, &stack);
			if (func)
			{
				func(&stack, line_number);
				if (!strcmp(new_line[0], "FATAL_PUSH_ERROR"))
				{
					fclose(file_pointer);
					free_array(new_line), free(current_line);
					free_stack(stack), free_array(this_array);
					exit(EXIT_FAILURE);
				}
			}
			free_array(this_array), this_array = NULL;
			free_array(new_line), new_line = NULL;
		}
		line_number++;
	}
	fclose(file_pointer), free(current_line), free_stack(stack);
}
