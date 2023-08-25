#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_pchar - function that prints char at top value of the stack.
 * @stack: pointer to the stack list.
 * @number: current working line number of a Monty bytecodes file.
 */
void op_pchar(stack_t **stack, unsigned int number)
{
	int i = 0;
	stack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	i = tmp->n;
	if (i < 0 || i > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", i->n);
}
