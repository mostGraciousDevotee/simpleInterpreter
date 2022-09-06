#include <stdio.h>

void echo(int cmd_argc, char *cmd_argv[])
{
  int i;
  
  for(i = 1; i < cmd_argc; i++)
  {
    printf("%s%s", *++cmd_argv, (cmd_argc > 1) ? " " : "");
  }
  
  putchar('\n');
}
