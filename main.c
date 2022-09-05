#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"

#define MAXCMD_ARG 64

int main(void)
{
  printf("Gabrielix Intepreter\nWritten by mostGraciousDevotee.\n\n");
  
  char *cmd_argv[MAXCMD_ARG];
  int cmd_argc;
  
  while((cmd_argc = getcmd(cmd_argv, MAXCMD_ARG)) >= 0)
  {
    if (strcmp(cmd_argv[0], "echo") == 0)
    {
      echo(cmd_argc, cmd_argv);
    }
    
    else if (strcmp(cmd_argv[0], "exit") == 0)
    {
      break;
    }
    
    else if (strcmp(cmd_argv[0], "help") == 0)
    {
      help(cmd_argc, cmd_argv);
    }
    
    else if (strcmp(cmd_argv[0], "wcount") == 0)
    {
      wcount(cmd_argc, cmd_argv);
    }
    
    else
    {
      printf("Command not found!\n\n");
    }
    
    afree(cmd_argv[0]);
  }
  
}
