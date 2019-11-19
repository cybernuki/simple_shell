#include "holberton.h"
/**
 * gcc -Wall -Werror -pedantic *.c -o shell && ./shell
 */
int main()
{
  char *buffer = NULL;
  size_t bufsize, characters;
  int size = 0, i;
  char **commands = NULL;
  
  promptMessage();
  while ((characters = getline(&buffer, &bufsize, stdin)) != EOF)
  {
    commands = array_to_strok(buffer, commands, &size);
    
    /*Pruebita*/
    for (i = 0; i < size; i++)
    {
        printf("%s\n", commands[i]);
    }
    
    /*free commands to re use without memory leaks*/
    for (i = 0; i < size; i++)
        free(commands[i]);
    free(commands);
    commands = NULL;
    
    promptMessage();
  }
  
  /*Free sections*/
  free(buffer);
  return (0);
}

