#include "holberton.h"

/**
 * promptMessage - print message
 * 
 * 
 */
void promptMessage()
{
  write(1, PROMPT, sizeof(PROMPT));
}
/**
 * printEnv - print env
 * 
 * @env: env
 */
void printEnv(char *env[])
{
  int i = 0;

  while (env[i])
  {
    write(1, env[i], _strlen(env[i]));
    write(1, "\n", 1);
    i++;
  }
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