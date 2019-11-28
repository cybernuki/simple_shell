#include "holberton.h"

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
char *_getpath(char **env)
{
  char *result = NULL;
    int i = 0;

   result = strtok(env[i], "=");
   while (result && _strcmp(result, "PATH") != 0 && env[i])
   {
       i++;
        result = strtok(env[i], "=");
   }
   if(_strcmp(result, "PATH") == 0)
   {
       result = strtok(NULL, "=");
   }
  return (result);
}

/*
 *
 */
char *test_env(const char *command, char **env)
{
  char *path, *dir, *copy;
  unsigned int dir_len, cmd_len;
  struct stat buff;

  path = _getpath(env);
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