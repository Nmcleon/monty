#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_1 - prints usage error.
 * @i: error: 0 (failed) 1 (usage).
 * Return: EXIT_FAILURE.
 */

int error_1(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}

/**
 * error_2 - prints file open error.
 * @c: file failed to open.
 * Return: EXIT_FAILURE.
 */
int error_2(const char *c)
{
		fprintf(stderr, "Error:  not %s\n", c);
		return (EXIT_FAILURE);
}

/**
 * read_error - A function that prints file read error message.
 * @file: Name of file failed to * Return: EXIT_FAILURE.
 */
void read_error(const char *file)
{
	fprintf(stderr, "Error: could not read %s\n", file);
}


/**
 * error - prints errors.
 * @i: index of error.
 * @num: number of lines with error.
 * Return: EXIT_FAILURE.
 */
int error(int i, unsigned int num)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
	     "can\'t pop an empty stack", "can\'t swap, stack too short",
	     "can\'t add, stack too short", "can\'t sub, stack too short",
	     "can\'t div, stack too short", "division by zero",
	     "can\'t mul, stack too short", "can\'t mod, stack too short",
	     "can\'t pchar, value out of range", "can\'t pchar, stack empty"};

	fprintf(stderr, "L%d: %s\n", num, errors[i]);
	return (EXIT_FAILURE);
}
