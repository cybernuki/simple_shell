#include "holberton.h"
/**
 *
 */
void promptMessage()
{
  write(1, PROMPT, sizeof(PROMPT));
}

/**
 *
 */
void printEnv(char *env[])
{
  int i = 0;
  
  while (env[i])
  {
    printf("%s\n",env[i]);
    i++;
  }
  
}