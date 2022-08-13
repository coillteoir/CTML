#ifndef _ESTACK_C 
#define _ESTACK_C

typedef struct
{
	int max;
	int size;
	char **elms;
}EStack;

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
		fprintf(output, "</");
		
		char *tag = *(s->elms + s->size);

		for(int i = 0; *(tag + i) > 32; i++)
		{
			fprintf(output, "%c", *(tag + i));
		}
		fprintf(output, ">\n");
		free(*(s->elms + s->size));
		s->size--;
	}
}

#endif
