#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - prints the values of the stack.
 * @stack: pointer to the top of a stack.
 * @line_num: number of the line.
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int num)
{
	stack_t *temp_stack = *stack;
	(void)num;

	while (temp_stack != NULL)
	{
		printf("%d\n", temp_stack->n);
		temp_stack = temp_stack->next;
	}
}
