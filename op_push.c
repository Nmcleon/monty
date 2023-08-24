#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* op_push - Push element to stack.
* @stack: pointer to the stack
* @num: number in the Monty byte file.
* @token: pointes to command
* Return: EXIT_SUCCESS
*/
int op_push(stack_t **stack, char **token, unsigned int num)
{
stack_t *n_stack;
int i = 0;
if (token[1] == NULL)
	return (error(0, num));
while (token[1][i])
	{
if (token[1][i] == '-' && i == 0)
		{
i++;
continue;
		}
if (token[1][i] < '0' || token[1][i] > '9')
		{
free_s(stack);
return (error(0, num));
		}
i++;
	}
n_stack = malloc(sizeof(stack_t));
if (n_stack == NULL)
	return (error_1(0));
n_stack->n = atoi(token[1]);
n_stack->prev = NULL;
if ((*stack) != NULL)
	{
(*stack)->prev = n_stack;
n_stack->next = *stack;
	}
else
	{
n_stack->next = NULL;
	}
*stack = n_stack;
return (EXIT_SUCCESS);
}
