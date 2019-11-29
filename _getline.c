#include "holberton.h"
/**
 * _getline - function to obtain the command
 * @buf: buffer
 * Return: result
 */
ssize_t _getline(char **buf)
{
	ssize_t result = 0;
	size_t var = 0;

	result = getline(buf, &var, stdin);

	return (result);
}
