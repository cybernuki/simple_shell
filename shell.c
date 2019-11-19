#include "holberton.h"
/**
 * gcc -Wall -Werror -pedantic *.c -o shell && ./shell
 */
int main()
{
  char *buffer = NULL;
  size_t bufsize, characters;
  int size = 0, status;
  pid_t pid;
  char **commands = NULL;

  promptMessage();
  while ((characters = getline(&buffer, &bufsize, stdin)) != EOF)
  {
    /*parseString(buffer)*/
    commands = array_to_strok(buffer, commands, &size);

    /*Hora de forjar la maza*/
    pid = fork();
    if (pid == -1)
    {
      perror("Error");
      return (1);
    }
    if (pid == 0)
    {
      execve(commands[0], commands, NULL);
    }
    else
    {
      wait(&status);
      /*free commands to re use without memory leaks*/
      free(commands);
      commands = NULL;
      promptMessage();
    }

    /*Pruebita
    for (i = 0; i < size; i++)
    {
      printf("[%p]: %s\n", commands[i], commands[i]);
    }

*/
  }
  if (characters == -1)
    return (EXIT_FAILURE);
  /*Free sections*/
  free(buffer);
  return (EXIT_SUCCESS);
}
