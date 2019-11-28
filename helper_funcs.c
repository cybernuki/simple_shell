#include "holberton.h"
#include "holberton.h"
/**
 * _strcmp - this function compare two strings
 * @s1: the first string
 * @s2: the second string
 (* a blank line
* Description: this function comparing two strings using the first value)?
(* section header: the header of this function is holberton.h)*
* Return: return a number depends os the resul fo comparation.
*/
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] != '\0' || s2[j] != '\0'; j++)
	{
		if (s1[j] != s2[j])
		{
			return (s1[j] - s2[j]);
		}
	}
	return (0);
}
/*
 *
 */
unsigned int _strlen_const(const char *name)
{
  unsigned int i = 0;
  while (name[i])
    ++i;
  return (i);
}
/*
 *
 */
unsigned int _strlen(char *s)
{
  unsigned int counter = 0;
  while (s[counter])
    ++counter;
  return (counter);
}
/**
 *
 */
char *_strncpy(char *dest, char *src, int n)
{
  int i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for (; i < n; i++)
    dest[i] = '\0';

  return (dest);
}
/*
 *
 */
char *_copyCmd(char *dest, char *src, const char *command, unsigned int dir_len, unsigned int cmd_len)
{
  unsigned int i, j;

  for (i = 0; i < dir_len && src[i] != '\0'; i++)
    dest[i] = src[i];
  dest[i] = '/';
  i++;
  for (j = 0; j < cmd_len; j++, i++)
    dest[i] = command[j];
  dest[i] = '\0';

  return (dest);
}