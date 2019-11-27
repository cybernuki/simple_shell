#include "holberton.h"

ssize_t _getline(char **buf)
{
    ssize_t result = 0;
    size_t var = 0;

    result = getline(buf, &var,stdin);

    if (_strcmp(*buf , EXIT_CMD) == 0)
	    result = -1;
    return (result);
}
