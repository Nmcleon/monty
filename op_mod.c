#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_mod - function that modules the second value from the top of a
 * stack: linked by the top value.
 * @stack: pointer to the stack list.
 * @number: line number of a Monty bytecodes file.
 * Description: The result stored in the second node
 *              from top and the top value is removed.
 */
void op_mod(stack_t **stack, unsigned int number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, number);
}
