#ifndef CLI_H_INCLUDED
#define CLI_H_INCLUDED

// BASIC COMMAND

void echo(int, char *[]);
void help(int, char*[]);

//MEMORY MANAGEMENT

char *alloc(int);
void afree(char *p);

// FINDS COMMAND

#define MAXLINE 128
int finds(int, char *[]);

// WORD FREQUENCY COUNT

int wcount(int, char *[]);

#endif // CLI_H_INCLUDED
