#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <stdio.h>

// WORD FREQUENCY COUNTER

// BINARY TREE

struct tnode
{
  // Pointer to Word
  char *word;
  
  // Word Occurence Coounter
  int count;
  
  // Tree's Child
  struct tnode *left;
  struct tnode *right;
};

// Memory Allocation for Tree Structure
struct tnode *talloc(void);

// Duplicate String Function
char *strdupl(char *);

// Print Binary Tree Function
void treeprint(struct tnode *, char *);

// Install Found Word into Binary Tree Fucntion
struct tnode *addtree(struct tnode *, char *);

// Convert or Sort Binary Tree According to its Word Frequency
struct tnode *addNumTree(struct tnode *, struct tnode *);
struct tnode *treeNumSort(struct tnode *, struct tnode *);

// ArrayBinSearch

extern char *junkWordTab[];
int arrayBinSearch(char *, char *[], int);

#endif // LEXER_H_INCLUDED
