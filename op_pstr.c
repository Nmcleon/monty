#include "monty.h"
/**
 * op_pstr - A function that prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: The pointer to the stack list.
 * @number: The current working line number of a Monty bytecodes file.
 */
void op_pstr(stack_t **stack, unsigned int number)
{
	stack_t *temp_s = *stack;
	(void)number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temp_s != NULL)
	{
		if (temp_s->n > 0 && temp_s->n <= 127)
		{
			printf("%c", temp_s->n);
			temp_s = temp_s->next;
		}
		else
			break;
	}
	printf("\n");
}
