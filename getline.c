#include <stdio.h>
#include <ctype.h>

int getline(char *line, int lim)
{
  int c, i = 0;
  
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    line[i++] = c;
  }
  
  if (c == '\n')
  {
    line[i++] = c;
  }
  
  if (c == EOF)
  {
    return EOF;
  }
  
  line[i] = '\0';
  
  return i;
}
