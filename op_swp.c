#include "monty.h"
/**
* op_swap - function that swaps the two values at the top of stack.
* @stack: pointer to  top of a stack list.
* @op_number: line number of a Monty bytecodes file.
*/
void op_swap(stack_t **stack, unsigned int op_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", op_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
