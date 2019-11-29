#include "holberton.h"

void _noItte(char *av, char **env)
{
    char *buff = NULL;

    (void)av;
    while (_getline(&buff) != -1)
    {
	    _execute(&buff, env);
    }
    free(buff);
}
