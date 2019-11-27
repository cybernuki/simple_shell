#include "holberton.h"

void _noItte(char *av)
{
    (void)av;
    char *buff = NULL;
    
    _getline(&buff);
    _execute(&buff);
}