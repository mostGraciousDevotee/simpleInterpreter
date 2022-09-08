#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#include "lexer.h"

char *junkWordTab[] =
{
    "A",
    "The", "There", "This",
    "We", "When",
    "a", "after", "all", "also", "an", "and", "any", "another","are", "as", "at",
    "b", "be", "because", "been", "before", "between", "both", "but", "by",
    "c", "can", "could",
    "do", "does",
    "each", "either", "else", "even",
    "f", "first", "for", "from",
    "h", "has", "have", "how", "however",
    "i", "if", "in", "instead", "into", "is", "it","its", "itself",
    "just",
    "like",
    "make", "may", "more", "most", "must",
    "n", "need", "new", "next", "no", "non", "not",
    "of", "on","one", "only", "or", "other",
    "p", "possible",
    "s", "same", "see", "several", "should", "since", "so", "some", "such",
    "t", "than", "that", "the", "their", "them", "then", "there", "these", "they", "this","to", "three", "two",
    "use", "used",
    "was", "way", "we", "when", "where", "which", "while", "will","with", "within", "without", "would",
    "x",
    "y", "you",
    "zero"
};

#define NJUNK (sizeof junkWordTab / sizeof junkWordTab[0])

// Word Frequency Counter

int wcount(int cmd_argc, char *cmd_argv[])
{
  // Optional Argument Flags
  
  int c, numerical = 0;
  
  while (--cmd_argc > 0 && (*++cmd_argv)[0] == '-')
  {
    while (c = *++cmd_argv[0])
      switch(c)
      {
          // Sort then Print from Largest Frequency to Lowest
        case 'n':
          numerical = 1;
          break;
        default:
          printf("wcount: illegal argument option %c\n", c);
          cmd_argc = 0;
          break;
      }
  }
  
  // Object Declaration
  struct tnode *root;
  char word[MAXWORD];
  
  // FILE Interface
  if (cmd_argc--)
  {
    fp = fopen(*cmd_argv, "r");
    
    if (fp == NULL)
    {
      printf("Failed to open %s\n\n", *cmd_argv);
    }
  }
  
  root = NULL;
  
  while (getword(word, MAXWORD, fp) != EOF)
  {
    // Filtering Junk Word
    int n;
    if ((n = arrayBinSearch(word, junkWordTab, NJUNK)) != -1)
    {
      continue;
    }
    
    if (isalpha(word[0]))
    {
      root = addtree(root, word);
    }
  }
  
  // Numerical Tree Sort
  
  struct tnode *numRoot;
  numRoot = NULL;
  
  if (numerical)
  {
    numRoot = treeNumSort(root, numRoot);
    putchar('\n');
    treeprint(numRoot);
  }
  
  else
  {
    putchar('\n');
    treeprint(root);
  }
  
  return 0;
}
