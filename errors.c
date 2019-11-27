#include "holberton.h"

void _fork_fail(char **buff)
{
    free(*buff);
    perror("Error:");
    exit(1);
}