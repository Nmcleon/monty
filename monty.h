#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


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
 * bytecode_run - runs  bytecode script.
 * @file: an open Monty bytecode script.
 * Return: EXIT_SUCCESS (success),EXIT_FAILURE (error)
 */
int bytecode_run(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int num = 0, status = EXIT_SUCCESS;

	while (get_line(&line, &len, file) != -1)
	{
		num++;
		if (empty(line, delim))
			continue;
		token = my_token(c, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			status = op_push(&stack, token, num);
		else
			status = exec(token, &stack, num);
		free(token);
		if (status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (status);
}

/**
 * free_s - frees memory allocated to stack.
 * @s: doubly linked list of stack.
 * Return: Nothing.
 */

void free_s(stack_t **s)
{
	stack_t *t = *s;

	while (*s)
	{
		t = (*s)->next;
		free(*s);
		*s = t;
	}
}
/* stack_is_empty function. If the stack is empty, don’t print anything*/
int stack_is_empty(stack_t *stack);

/*main functions*/
int op_push(stack_t **stack, char **token, unsigned int num);
void pall(stack_t **stack, unsigned int num);
int exec(char **token, stack_t **stack, unsigned int num);

/*error functions*/
int error_1(int i);
int error_2(const char *c);
int error(int i, unsigned int num);
void read_error(const char *file);


#endif /* MONTY_H */
