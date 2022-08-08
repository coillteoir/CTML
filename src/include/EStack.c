#ifndef _ESTACK_C 
#define _ESTACK_C

#include "EStack.h"

void EPush(EStack * s, char * tag, FILE * output)
{
	for(int i = 0; i < s->size; i++)
		fprintf(output, "\t");

	s->size++;
	
	*(s->elms + s->size) = tag;
	
	fprintf(output,"<%s>\n",tag);
}

void EPop(EStack * s, FILE * output)
{
	for(int i = 0; i < s->size - 1; i++)
		fprintf(output, "\t");

	if(s->size >= 0)
	{
		fprintf(output,"</%s>\n",*(s->elms + s->size));
		free(*(s->elms + s->size));
		s->size--;
	}
}

#endif
