#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/*main functions*/
int op_push(stack_t **stack, char **token, unsigned int num);
void pall(stack_t **stack, unsigned int num);
int exec(char **token, stack_t **stack, unsigned int num);


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
	free_s(&stack);
	free(line);
	return (status);
}

**
 * my_token - split the line.
 * @line: pointer to bytecode line.
 * @delim: array (5 delimiters " \n\t\a\b".)
 * Return: pointer to token.
 */
char **my_token(char *c, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (c == NULL || !*c)
		return (NULL);

	bufsize = strlen(c);
	if (bufsize == 0)
		return (NULL);
	token = malloc(bufsize * sizeof(char *));
	if (token == NULL)
	{
		free(c);
		free(token);
		exit(error_1(0));
	}
	tokens = strtok(c, delim);
	if (tokens == NULL)
	{
		free(token);
		free(c);
		return (NULL);
	}
	while (tokens != NULL)
	{
		token[i] = tokens;
		i++;
		tokens = strtok(NULL, delim);
	}
	token[i] = '\0';
	return (token);
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
/**
 * empty - checks if line only contains delimiters.
 * @line: pointer to the line.
 * @delims: string with delimiter characters.
 * Return: 1 (delimiters), else 0.
 */
int empty(char *line, char *delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}

	return (1);
}

/* stack_is_empty function. If the stack is empty, don’t print anything*/
int stack_is_empty(stack_t *stack);



/*error functions*/
int error_1(int i);
int error_2(const char *c);
int error(int i, unsigned int num);
void read_error(const char *file);


#endif /* MONTY_H */
