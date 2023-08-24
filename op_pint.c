#include "monty.h"
/**
 * op_pint - Function that prints the top value of the stack.
 * @stack: Double pointer to the top of the stack.
 * @number: Line number of the opcode being executed.
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
