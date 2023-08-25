#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_sub - A function that subtracts the second value from the top of a
 * stack: linked by the top value.
 * @stack: pointer to the stack list.
 * @number: line number of a Monty bytecodes file.
 * Description: result is stored in second node
 *              from top and the top value removed.
 */
void op_sub(stack_t **stack, unsigned int number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	op_pop(stack, number);
}
