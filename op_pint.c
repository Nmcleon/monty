#include "monty.h"

/**
 * pint - function prints the top value of the stack.
 * @stack: pointer to the stack list.
 * @line_number: working line number of a Monty bytecodes file. 
 */

void pint(stack_t **stack, unsigned int number)
{
	stack_t *temp_s = *stack;

	if (!temp_s)
	{
		f_errors(1, number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp_s->n);
}
