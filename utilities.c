#include "holberton.h"
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
/**
 * 
 */
void promptMessage()
{
  write(1, PROMPT, sizeof(PROMPT));
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
/**
 *
 */
void printEnv(char *env[])
{
  int i = 0;

  while (env[i])
  {
    printf("%s\n", env[i]);
    i++;
  }
}
/*
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
/**
 * 
 */
unsigned int findSemi(char *dir)
{
  unsigned int semiColon, i;

  i = 0;
  semiColon = 1;
  while (dir[i])
  {
    if (dir[i] == ';')
      ++semiColon;
    ++i;
  }

  return (semiColon);
}
/**
 * 
 */
char *_getenv(const char *name)
{
  extern char **environ;
  char *environ_value, *nameCopy;
  unsigned int i, length;

  length = _strlen_const(name);
  nameCopy = malloc((sizeof(char) * length) + 1);

  i = 0;
  while (name[i])
  {
    nameCopy[i] = name[i];
    ++i;
  }
  nameCopy[i] = '\0';

  i = 0;
  environ_value = strtok(environ[i], "=");
  while (environ[i])
  {
    if (_strcmp(environ_value, nameCopy))
    {
      environ_value = strtok(NULL, "\n");
      free(nameCopy);
      return (environ_value);
    }
    ++i;
    environ_value = strtok(environ[i], "=");
  }

  free(nameCopy);
  return (NULL);
}

/*
 *
 */
char *test_env(const char *command)
{
  char *path, *dir, *copy;
  unsigned int dir_len, cmd_len;
  struct stat buff;

  path = _getenv("PATH");
  dir = strtok(path, ":");
  while (dir != NULL)
  {
    dir_len = _strlen(dir);
    cmd_len = _strlen_const(command);
    copy = malloc (sizeof(char*) * (dir_len + cmd_len + 1));
    _copyCmd(copy, dir, command, dir_len, cmd_len);
    
    if (stat(copy, &buff) == 0) 
        return (copy);
      
    dir = strtok(NULL, ":");
  }

  free(copy);
  return (NULL);
}
