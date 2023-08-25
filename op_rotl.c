#include "monty.h"

/**
 * op_rotl - A function that rotates the stack to the top.
 * @stack: The pointer to the stack list.
 * @number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void op_rotl(stack_t **stack, unsigned int number)
{
	int i;
	stack_t *temp_s = *stack;
	(void)number;

	if (*stack)
	{
		i = temp_s->n;
		while (temp_s->next != NULL)
		{
			temp_s->n = temp_s->next->n;
			temp_s = temp_s->next;
		}
		temp_s->n = i;
	}
}
