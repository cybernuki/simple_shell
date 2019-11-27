#include "holberton.h"
/**
 * gcc -Wall -Werror -pedantic *.c -o shell && ./shell
 */

void exitHandler(int sig)
{
  (void)sig;
  write(STDOUT_FILENO, "\n$ ", 3);
}
int main(int ac, char **av, char **env)
{
  char *buffer;
  size_t bufsize;
  ssize_t getlineCha;
  int size, status;
  pid_t pid;
  struct stat Stat;
  char *all_dir, **commands = NULL;

  (void)ac;
  (void)av;
  buffer = NULL, bufsize = 0, size = 0;
  if (isatty(STDIN_FILENO))
    write(STDIN_FILENO, "$ ", 2);

  /* CTRL -C */
  signal(SIGINT, exitHandler);
  while ((getlineCha = getline(&buffer, &bufsize, stdin)))
  {
    /* check eof */
    if (getlineCha == EOF)
      _EOF(buffer);

    /*parseString(buffer)*/
    commands = array_to_strok(buffer, commands, &size);

    /*Hora de forjar la maza*/
    pid = fork();
    if (pid == -1)
      fork_fail();
    if (pid == 0)
    {
      if (commands == NULL)
        commandNull(buffer);
    /*Break the molde*/
      else if (_strcmp("exit", commands[0]))
          _exit_end(buffer, commands);
      else if (_strcmp("env", commands[0]))
          _print_env(buffer, commands, env);
      /*if (_strcmp(commands[0], EXIT_COMMAND))
        _exit_end(buffer, commands);*/      
      else if (stat(commands[0], &Stat) == 0)
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
        {
          perror("ERROR\n");
        }
      }
    }
    else
    {
      
      wait(&status);
      if (commands == NULL)
        free_commands_buff(buffer, commands);
      else if (_strcmp("exit", commands[0]))
        _exit_end(buffer, commands);
      /*free commands to re use without memory leaks*/
      free(commands);
      commands = NULL;
      promptMessage();
    }
    bufsize = 0; buffer = NULL;
  }
  free(buffer);
  /*Free sections*/
  if (getlineCha == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
