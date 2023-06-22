#include "monty.h"
#include <string.h>
#include <stdlib.h>

void line_bringer(char **lineptr, size_t *n, char *buffer, size_t ind)
{
    if (*lineptr == NULL || *n < ind)
    {
        if (ind > BUFSIZE)
            *n = ind;
        else
            *n = BUFSIZE;

        *lineptr = realloc(*lineptr, *n * sizeof(char));
    }

    memcpy(*lineptr, buffer, ind);
    free(buffer);
}

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t ind;
    ssize_t retval;
    char *buffer;
    static ssize_t input = 0;

    if (input != 0)
        return -1;

    buffer = malloc(BUFSIZE * sizeof(char));
    if (buffer == NULL)
        return -1;

    ind = 0;
    while (ind < BUFSIZE - 1)
    {
        int c = fgetc(stream);
        if (c == EOF)
        {
            if (ind == 0)
            {
                free(buffer);
                return -1;
            }
            break;
        }

        buffer[ind++] = c;
        if (c == '\n')
            break;
    }

    buffer[ind] = '\0';
    line_bringer(lineptr, n, buffer, ind);
    retval = ind;

    input = 0;

    return retval;
}
