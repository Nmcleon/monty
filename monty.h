#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

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

/*main functions*/
int op_push(stack_t **stack, char **token, unsigned int num);
void pall(stack_t **stack, unsigned int num);
int error_1(int i);
int error_2(const char *c);
void read_error(const char *file);
int error(int i, unsigned int num);
int empty(char *line, char *delim);
void free_s(stack_t **s);
char **my_token(char *c, char *delim);
int bytecode_run(FILE *file);
int execute(char **token, stack_t **stack, unsigned int num);
int getline(char **line, size_t *len, FILE *file);

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

#endif /* MONTY_H */
