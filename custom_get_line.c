#include "monty.h"

/**
 * custom_get_line - Custom version of getline
 * @line: Pointer to the line buffer.
 * @len: Pointer to the buffer size.
 * @file: File pointer.
 * Return: Number of characters read, or -1 on failure.
 */
int custom_get_line(char **line, size_t *len, FILE *file)
{
    ssize_t read = getline(line, len, file);
    if (read == -1)
    {
        if (feof(file)) // End of file
        {
            return (-1);
        }
        perror("Error reading line");
        exit(EXIT_FAILURE);
    }
    return (read);
}
