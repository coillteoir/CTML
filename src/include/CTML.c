#ifndef _CTML_C
#define _CTML_C 1

#include "EStack.h"

int noSpace(char * string, int len) {
    char * d = string;

    bool isText = 0;
    bool solo = 0;

    int spaces = 0;

    do {
        if(*(d - 1) == '(') {
            isText = true;
            if(*(d - 2) == '%')
                solo = true;
            else
                solo = false;
        }
        if(*d == ')') {
            if(solo == false)
                isText = false;
        }
        if(*(d - 1) == '{') {
            isText = true;
        }
        if(*d == '}') {
            isText = false;
        }

        while((*d == ' ' && isText == false) || *d == '\t' || *d == '\n') {
            ++d;
            ++spaces;
        }
    } while((*string++ = *d++));

    return len - spaces;
}

char *exTag(char * inStr, size_t open, size_t close) {
    char *tag = calloc(close-open, 1);

    int index = 0;

    for(size_t i = open + 1; i < close; i++) {
        *(tag + index) = *(inStr + i);
        index++;
    }

    return tag;
}

char * compile(FILE * input, FILE * output) {
    /*Step 1: Extract text from the FILE*/

    /*1.1 Find length of the file*/

    fseek(input, 0, SEEK_END);
    int flen = ftell(input);
    fseek(input,0,0);

    /*1.2 Copy text from file into memory*/

    char * srcText = calloc(flen,sizeof(char));

    char * t = srcText;

    for(char c = 0; !feof(input); c = fgetc(input)) {
        *(t) = c;
        ++t;
    }

    flen--;

    for(int i = 1; i < flen; i++)
        *(srcText + i - 1) = *(srcText + i);

    /*Step 2: Remove whitespace from source text */

    flen = noSpace(srcText, flen);

    /*Step 3: Count the amount of elements in the source*/

    unsigned char ignore = 0;
    int bracks = 0;
    int parens = 0;
    int tcount = 0;

    char *s = srcText-1;

    char currb = 0;

    /*Ensure parentheses and brackets are matched.*/

    while(*(++s)) {
        /*Make sure ignored characters aren't counted */

        if(*s == '\\') {
            ignore = 1;
        }

        if((*s == '(' || *s == ')' || *s == '{'  || *s == '}') && ignore == 1) {
            ignore = 0;
        } else if(*s == '(' &&  !ignore) {
            currb = '(';
            parens++;
            tcount++;
        } else if(*s == ')' && currb == '(' &&  !ignore) {
            currb = 0;
            parens--;
        } else if(*s == '{' &&  !ignore) {
            bracks++;
        } else if(*s == '}' &&  !ignore) {
            bracks--;
        }
    }

    if(parens != 0) {
        fprintf(stderr, "Fatal: Mismatched brackets in tags");
        exit(1);
    } else if(bracks != 0) {
        fprintf(stderr, "Fatal: Mismatched curly braces");
        exit(1);
    }

    /*    Step 4: Extract tags from source */

    EStack stack = {
        .max = tcount,
        .size = 0,
        .elms = 0
    };

    stack.elms = malloc(sizeof(char*) * stack.max);

    for(size_t i = 0; i < strlen(srcText); i++) {

        static int open = 0;
        static int close = 0;
        static bool inTag = false;
        static bool ignore = false;

        char c = *(srcText + i);

        if(c == '\\') {
            ignore = true;
        }

        if(c == '(' && ignore == false) {
            open = i;
            inTag = true;
        } else if(c == ')' && ignore == false) {
            close = i;
            inTag = false;
        } else if(c == '{'&& ignore == false) { //if open curly brace is detected then there is a push to the stack
            EPush(&stack, exTag(srcText,open,close),output);
        } else if(c == '}' && ignore == false) { //if a closed curly brace is detected then there is a pop from the stack
            EPop(&stack, output);
        } else {
            if(inTag == false) {
                if(!((c == '\\' && ignore)))
                    fprintf(output,"%c",c);

                if(ignore && (c == '{' || c == '}' ||c == '(' || c ==  ')'))
                    ignore = false;
            }
        }
    }

    return srcText;
}

#endif
