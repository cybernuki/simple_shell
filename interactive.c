#include "holberton.h"

void _itte(char **env)
{
    char *buff = NULL;
    ssize_t result = 0;

    while (1)
    {
        write(1, "$ ", 2);
        result = _getline(&buff);

        if (result == -1)
        {
            write(1, "\n", 1);
            free(buff);
            break;
        }
        else if (result == 1)
        {
            free(buff);
            continue;
        }
        if (_strcmp(buff, "env") == 0)
		printEnv(env);
        else
            _execute(&buff, env);
    }
}
