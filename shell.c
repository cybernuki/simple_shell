#include "holberton.h"
/**
 * gcc -Wall -Werror -pedantic *.c -o shell && ./shell
 */
int main(int ac, char **av, char **env)
{
  char *buffer;
  size_t bufsize;
  int size = 0, status;
  pid_t pid;
  struct stat Stat;
  char *all_dir, **commands = NULL;

  (void)ac;
  (void)av;
  buffer = NULL;
  if (isatty(STDIN_FILENO))
    promptMessage();

  while ((getline(&buffer, &bufsize, stdin)) != EOF)
  {
    /*parseString(buffer)*/
    commands = array_to_strok(buffer, commands, &size);

    /*Break the molde*/
    if (!strncmp(buffer, EXIT_COMMAND, 4))
    {
      free(commands);
      commands = NULL;
      break;
    }
    else if (!strncmp(buffer, ENV_COMMAND, 3))
    {
      free(commands);
      commands = NULL;
      printEnv(env);
      promptMessage();
      continue;
    }
    /*Hora de forjar la maza*/
    pid = fork();
    if (pid == -1)
    {
      perror("Error");
      exit(1); /*Cambiado return(1);*/
    }
    if (pid == 0)
    {
      if (stat(commands[0], &Stat) == 0)
        execve(commands[0], commands, env);
      else
      {
        size = 0;
        all_dir = test_env(commands[0]);
        if (all_dir)
        {
          execve(all_dir, commands, env);
          /* how 2 free all_dir */
          free(all_dir);          
        }
        else
          printf("ERROR\n");
      }
    }
    else
    {
      wait(&status);
      /*free commands to re use without memory leaks*/
      free(commands);
      commands = NULL;
      promptMessage();
    }
  }
  /*Pruebita
    for (i = 0; i < size; i++)
    {
      printf("%s\n", commands[i]);
    }*/

  free(buffer);
  /*Free sections*/
  return (EXIT_SUCCESS);
}
