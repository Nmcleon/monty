#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - function that adds the two top values of stack.
 * @stack: pointer to stack list.
 * @number: line number of Monty bytecodes file.
 * Description: the second value node result stored
 *              from top and the top value is removed.
 */
void op_add(stack_t **stack, unsigned int number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, number);
}
