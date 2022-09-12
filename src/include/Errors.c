#ifndef _ERRORS_C
#define _ERRORS_C

int ExtenCheck(char * file, char * ex)
{

	char * n = 0;
	while(*++file)
	{		
		if(*file == '.')
		{
			n = file + 1;
		}
	}

	if(strcmp(n, ex) == 0) return 0;
	else return 1;
}



#endif
