#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/CTML.h"
#include "include/EStack.h"
#include "include/Errors.h"

#define VERSION "0.1"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		fprintf(stdout, "CTML %s\n", VERSION);
		fputs("Usage: ctml <input.ctml> [output.html]\n", stdout);
		return 0;
	}

	FILE * input = fopen(argv[1], "r");
	FILE * output = NULL;

	if(argc != 2)
		output = fopen(argv[2], "w+");
	else
		output = fopen("index.html", "w+");

	if(!input)
	{
		fputs("Fatal : Input file cannot be opened\n",stderr);
		return 1;
	}

	if(!output)
	{
		fputs("Fatal : Output file cannot be created\n",stderr);
		return 1;
	}

	compile(input,output);

	return 0;
}
