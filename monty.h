#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#define DELIM " \n\t\r"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * new_line - my global variable
 */
char **new_line;

void push_m(stack_t **stack, unsigned int line_number);
void pall_m(stack_t **stack, unsigned int line_number);

void full_path(char **path_name, char *file_name);
void parse_file(char *path_name);
char **get_tokens(char *str, char *delim);
void (*get_op_code(char **array, unsigned int line_number, stack_t **stack))\
	     (stack_t **stack, unsigned int line_number);
void num_args(int argc);
void file_exists(char *path_name, char *file_name);
void free_array(char **array);
void free_stack(stack_t *stack);

#endif
