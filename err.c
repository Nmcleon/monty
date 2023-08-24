#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * error_1 - the function name
  * @i: parameter of type int
  * Return: int .
 */
int error_1(int i)
{
char *error[2] = {"Error: malloc failed", "USAGE: monty file"};
fprintf(stderr, "%s\n", error[i]);
return (EXIT_FAILURE);
}
/**
* error_2 - prints file open error.
* @c: file failed to open
* Return: EXIT_FAILURE
*/
int error_2(const char *c)
{
fprintf(stderr, "Error:  not %s\n", c);
return (EXIT_FAILURE);
}

/**
* error - prints errors.
* @i: index to type of error
* @num: number of line containing error
* Return: EXIT_FAILURE
*/
int error(int i, unsigned int num)
{
char *errors[] = {"usage:
	     "can\'t pop an empty stack", "can\'t swap, stack too short",
	     "can\'t add, stack too short", "can\'t sub, stack too short",
	     "can\'t div, stack too short", "division by zero",
	     "can\'t mul, stack too short", "can\'t mod, stack too short",
"can\'t pchar, value out of range", "can\'t pchar, stack empty"};
fprintf(stderr, "L%d: %s\n", num, errors[i]);
return (EXIT_FAILURE);
}
