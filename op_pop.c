#include "monty.h"
/**
 * op_pop - function removes top value of a stack.
 * @stack: pointers to stack_t list.
 * @number: line number of Monty bytecodes file.
 */
void op_pop(stack_t **stack, unsigned int number)
{
	stack_t *temp_s = *stack;

	if (!temp_s)
	{
		f_errors(2, number);
		exit(EXIT_FAILURE);
	}

	if (temp_s->next)
		temp_s->next->prev = temp_s->prev;
	*stack = temp_s->next;
	free(temp_s);
}
