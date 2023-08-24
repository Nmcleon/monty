#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack's head.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (stack_is_empty(*stack))
    {
        fprintf(stderr, "pall: stack empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        stack_t *tmp = stack_pop(stack);
        pall(stack, line_number);
        stack_push(stack, tmp);
    }
}
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
