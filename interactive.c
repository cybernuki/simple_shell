#include "holberton.h"

void _itte(void)
{
    char *buff = NULL;
    ssize_t result = 0;

    while (1)
    {
        write(1, "$ ", 2);
        result = _getline(&buff);

        if (result == -1)
        {
            free(buff);
            break;
        }
        else if (result == 1)
        {
            free(buff);
            continue;
        }
        _execute(&buff);
    }
}