#include <stdio.h>
#include <string.h>

#include "cli.h"
#define MAXLINE 128

int finds(int cmd_argc, char *cmd_argv[])
{
  // Optional Argument Flags
  
  int c, except = 0, number = 0, found = 0;
  while (--cmd_argc > 0 && (*++cmd_argv)[0] == '-')
  {
    while (c = *++cmd_argv[0])
      switch (c)
      {
          // Inverse Finds
          
        case 'x':
          except = 1;
          break;
          
          // Add Line Number
          
        case 'n':
          number = 1;
          break;
          
        default:
          printf("find: illegal option %c\n", c);
          cmd_argc = 0;
          found = -1;
          break;
      }
  }
  
  // Outputting to Specified Filename
  
  FILE *fp;
  FILE *fp2;
  
  int outfile = 0;
  
  if(cmd_argc--)
  {
    // Opening FILE
    
    fp = fopen(*cmd_argv++, "r");
    if (cmd_argc == 1)
    {
      outfile = 1;
      fp2 = fopen(*cmd_argv, "w");
      
      if (fp2 == NULL)
        fprintf(stderr, "finds failed to open fp2");
      
      --cmd_argc;
    }
  }
  
  // cmd_argc Guard
  
  if (cmd_argc != 0)
  {
    printf("usage find -x -n filename\n");
  }
  
  else
  {
    // Inputting Pattern
    
    char pattern[MAXLINE];
    
    printf("Please type the pattern you want to find: ");
    getline(pattern, MAXLINE);
    pattern[strlen(pattern) - 1] = '\0';
    
    // finds Command Main Loop
    
    char *line = alloc(MAXLINE);
    long lineno = 0;
    
    while ((line = fgets(line, MAXLINE, fp)) != NULL)
    {
      // Print String when Pattern Found in Line
      lineno++;
      if ((strindex(line, pattern) >= 0) != except)
      {
        if (number)
          printf("%ld: ", lineno);
        
        if (outfile)
          fputs(line, fp2);
        
        found++;
      }
    }
  }
  
  // Print Total Pattern Found.
  printf("Found %d results.\n\n", found);
  
  return found;
}
