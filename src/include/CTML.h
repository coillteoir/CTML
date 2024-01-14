#ifndef _CTML_H
#define _CTML_H 1

#include "CTML.c"

char * compile(FILE *, FILE *);
int noSpace(char *, int);
char *exTag(char *, size_t, size_t);

#endif
