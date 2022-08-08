#ifndef _ESTACK_H
#define _ESTACK_H

typedef struct
{
	int max;		//Max length of the stack.
	int size;		//Current size of the stack.
	char **elms;	//Elements of the stack, a pointer to strings.
}EStack;

void EPush(EStack *, char *, FILE *);
void EPop(EStack *, FILE *);

#endif
