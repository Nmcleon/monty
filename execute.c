#include "monty.h"

/**
* execute - Execute the function if there's a match.
* @token: Contains the opcode to execute.
* @stack: Linked list representation of stack.
* @num: Line number where the opcode was found.
* Return: EXIT_SUCCESS (success), or EXIT_FAILURE (failure).
*/
int execute(char **token, stack_t **stack, unsigned int num)
{
	unsigned int i = 0;

instruction_t op[] = {
{"pall", pall},
{"pint", op_pint},
{"null", NULL}
};
		for (i = 0; op[i].opcode != NULL; i++)
		{
			if (strcmp(op[i].opcode, token[0]) == 0)
			{
				op[i].f(stack, num);
				return (EXIT_SUCCESS);
			}
		}
		free_s(stack);
		fprintf(stderr, "L%i: unknown instruction %s\n", num, token[0]);
		return (EXIT_FAILURE);
	}
