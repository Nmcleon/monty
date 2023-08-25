#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_div - Divides the second value from the top of the stack by the top value.
 * @stack: Pointer to the stack list.
 * @num: Line number in the Monty bytecode file.
 * Description: The result is stored in the second node from the top, and the top value is removed.
 */
void op_div(stack_t **stack, unsigned int num)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = i;
	monty_pop(stack, num);
}
