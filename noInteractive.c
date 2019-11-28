#include "holberton.h"

void _noItte(char *av, char **env)
{

    char *buff = NULL;

    (void)av;
    _getline(&buff);
    _execute(&buff, env);
}
