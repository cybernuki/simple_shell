#include "holberton.h"
/**
 *
 */
int _strcmp(char *s1, char *s2)
{
  unsigned int i = 0;

  while (s1[i])
  {
    if (s1[i] != s2[i])
      return (0);
    ++i;
  }

  return (1);
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