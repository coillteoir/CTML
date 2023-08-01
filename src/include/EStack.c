#ifndef _ESTACK_C 
#define _ESTACK_C 1

typedef struct
{
	int max;
	int size;
	char **elms;
}EStack;

void EPush(EStack * stack, char * tag, FILE * output)
{
	for(int i = 0; i < stack->size; i++)
		fprintf(output, "\t");
	
	stack->size++;
	
	*(stack->elms + stack->size) = tag;
	
	fprintf(output,"<%s>\n",tag);
}

void EPop(EStack * stack, FILE * output)
{
	for(int i = 0; i < stack->size - 1; i++)
		fprintf(output, "\t");
	
	if(stack->size >= 0)
	{
		fprintf(output, "</");
		
		char *tag = *(stack->elms + stack->size);

		for(int i = 0; *(tag + i) > 32; i++)
		{
			fprintf(output, "%c", *(tag + i));
		}

		fprintf(output, ">\n");

		if(stack->size == 1)
			return;
		free(tag);
		stack->size--;
	}
}

#endif
