#include "monty.h"
/**
 * op_pop - function removes top value of a stack.
 * @stack: pointers to stack_t list.
 * @number: line number of Monty bytecodes file.
 */
void op_pop(stack_t **stack, unsigned int number)
{
	stack_t *temp;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
