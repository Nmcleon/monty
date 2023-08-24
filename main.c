#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

/**
  * main - The entry point of the program
  * @argc: parameter of type int .
  * @argv: parameter of type char *.
  * Return: int .
 */
int main(int argc, char *argv[])
{
FILE *file = NULL;
int status = EXIT_SUCCESS;
if (argc != 2)
{
return (error_1(1));
}
file = fopen(argv[1], "r");
if (file == NULL)
{
return (error_2(argv[1]));
}
status = bytecode_run(file);
fclose(file);
return (status);
error_2(argv[1]);
bytecode_run(file);
exit(EXIT_SUCCESS);
return (0);
}
