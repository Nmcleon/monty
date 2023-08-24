#include "monty.h"

/**
 * execute - execute the function if there's a match.
 * @token: contains the opcode to execute.
 * @stack: linked list representation of stack.
 * @num:  where the opcode was found.
 * Return: EXIT_SUCCESS (success), or EXIT_FAILURE (failure.)
 */

int execute(char **token, stack_t **stack, unsigned int num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, num);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", num, token[0]);
	return (EXIT_FAILURE);
}
