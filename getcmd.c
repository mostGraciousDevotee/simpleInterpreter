#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "cli.h"

int getcmd(char *cmd_argv[], int maxcmd_arg)
{
  int cmd_argc = 0;
  int c;
  char arg[maxcmd_arg];
  
  int ai = 0;
  char *p;
  
  printf("\nPlease enter your command: ");
  
  while((c = getchar()) != EOF && c != '\n')
  {
    if (c == ' ' || c == '\t')
    {
      arg[ai] = '\0';
      
      if (cmd_argc >= maxcmd_arg || (p = alloc(ai+1)) ==  NULL)
      {
        return -1;
      }
      
      else
      {
        strcpy(p, arg);
        cmd_argv[cmd_argc++] = p;
      }
      ai = 0;
    }
    
    else
    {
      arg[ai++] = c;
    }
  }
  
  if (c == '\n')
  {
    arg[ai] = '\0';
    if (cmd_argc >= maxcmd_arg || (p = alloc(ai+1)) == NULL)
    {
      return -1;
    }
    
    else
    {
      strcpy(p, arg);
      cmd_argv[cmd_argc++] = p;
    }
  }
  
  else if (c == EOF)
  {
    return c;
  }
  
  return cmd_argc;
}
