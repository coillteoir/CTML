#ifndef _CTML_C
#define _CTML_C 1

#include "EStack.h"

void noSpace(char * s, int * len)
{
	char * d = s;

	unsigned char isText = 0;
	unsigned char ignore = 0;
	int spaces = 0;

	do
	{
		if(*d == '\\')
			ignore = 1;

		if(*(d - 1) == '(')
		{	
			isText = 1;
		}
		if(*d == ')')
		{
			isText = 0;
		}
		if(*(d - 1) == '{')
		{
			isText = 1;
		}
		if(*d == '}')
		{
			isText = 0;
		}


		while((*d == ' ' && isText == 0) || *d == '\t' || *d == '\n')
		{	
			++d;
			++spaces;
		}
		ignore = 0;
	}
	while(*s++ = *d++);
	
	*len -= spaces;
}

char *exTag(char * inStr, size_t open, size_t close)
{
		char *tag = calloc(close-open, 1);

		int index = 0;

		for(int i = open + 1; i < close; i++)
		{
			*(tag + index) = *(inStr + i);
			index++;
		}
		
		return tag;
}

int compile(FILE * input, FILE * output)
{
	/*	Step 1: Extract text from the FILE	*/
	
	/*	1.1 Find length of the file	*/
	
	fseek(input, 0, SEEK_END);
	int flen = ftell(input);
	fseek(input,0,0);
	
	/*	1.2 Copy text from file into memory	*/
	
	char * srcText = calloc(flen ,sizeof(char));
	
	char * t = srcText;

	for(char c = 0; !feof(input); c = fgetc(input))
	{
		*(t) = c;
		++t;
	}

	flen--;

	for(int i = 1; i < flen; i++)
		*(srcText + i - 1) = *(srcText + i);

	/*	Step 2: Remove whitespace from source text */
	
	noSpace(srcText, &flen);
	
	/*	Step 3: Count the amount of elements in the source*/

	int openb = 0;
	int closeb = 0;
	int openc = 0;
	int closec = 0;

	char *s = srcText-1;

	char currb = 0;
	char currc = 0;

	int elms = 0;
	int pairs = 0;

	while(*(++s))
	{
		if(*s == '(')
		{	
			currb = '(';
			openb++;
		}
		if(*s == ')' && currb == '(')	
		{	
			currb = 0;
			closeb++;
		}
		if(*s == '{')	
			openc++;
		if(*s == '}')
			closec++;

	}

	if(openc != closec)
	{
		fprintf(stderr, "Fatal: Mismatched brackets in tags");
		exit(1);
	}
	else if(openb != closeb)
	{
		fprintf(stderr, "Fatal: Mismatched curly braces");
		exit(1);
	}

	/*	Step 4: Extract tags from source */

	EStack s1 = {.max = openc,
				.size = 0,
				.elms = 0};

	s1.elms = malloc(sizeof(char*) * s1.max);

	for(int i = 0; i < strlen(srcText); i++)
	{		
		static int open = 0;
		static unsigned char inTag = 0;
		static unsigned char ignore = 0;
		static int close = 0;
	

		if(*(srcText + i) == '\\')
			ignore = 1;


		if(*(srcText + i) == '(' && ignore == 0)
		{
			open = i;
			inTag = 1;
		}
		else if(*(srcText + i) == ')' && ignore == 0)
		{
			close = i;
			inTag = 0;
		}
		else if(*(srcText + i) == '{'&& ignore == 0) //if open curly brace is detected then there is a push to the stack
		{
			EPush(&s1, exTag(srcText,open,close),output);	
		}
		else if(*(srcText + i) == '}' && ignore == 0)//if a closed curly brace is detected then there is a pop from the stack
		{
			EPop(&s1, output);
		}
		else
		{
			if(inTag == 0)
			{
				if(*(srcText + i) == '\\' && ignore)
					(void)0; //this acts like python's pass 	
				else
					fprintf(output,"%c",*(srcText + i)); 
							
				if(ignore && (*(srcText + i) == '{' || *(srcText + i) == '}' ||*(srcText + i) == '(' || *(srcText + i) ==  ')'))
					ignore = 0;
			}
		}

	}

	free(srcText);
}	

#endif
