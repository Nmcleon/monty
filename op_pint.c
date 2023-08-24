#include "monty.h"

/**
 * op_pint - function prints the top value of the stack.
 * @stack: pointer to the stack list.
 * @line_number: working line number of a Monty bytecodes file. 
 */

void op_pint(stack_t **stack, unsigned int number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	
	printf("%d\n", (*stack)->n);
}
