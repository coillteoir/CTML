#ifndef _ERRORS_C
#define _ERRORS_C

int ExtenCheck(char * file, char * ex)
{

    char * extension = 0;
    while(*++file)
    {		
    	if(*file == '.')
    	{
    		extension = file + 1;
    	}
    }

    if(strcmp(extension, ex) == 0) return 0;
    else return 1;
}

#endif
