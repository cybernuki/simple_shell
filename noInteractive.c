#include "holberton.h"

void _noItte(char *av)
{

    char *buff = NULL;

    (void)av;
    _getline(&buff);
    _execute(&buff);
}
