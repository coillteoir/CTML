#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "include/CTML.h"
#include "include/Errors.h"

#define VERSION 0.1

int main(int argc, char **argv) {

    if(argc == 1) {
        fputs("Fatal: No input files detected\n",stderr);
        return 0;
    }

    if(strcmp(argv[1], "--version") == 0) {
        printf("CTML v%0.1f\nCopyright (C) David Lynch 2024\n",VERSION);
        return 0;
    }

    if(ExtenCheck(argv[1], "ctml") == 1) {
        fprintf(stderr, "Fatal: CTML input file not detected.\n");
        exit(1);
    }

    FILE * input = fopen(argv[1], "r");
    FILE * output = NULL;

    if(argc != 2)
        output = fopen(argv[2], "w+");
    else
        output = fopen("index.html", "w+");

    if(!input) {
        fputs("Fatal : Input file cannot be opened\n",stderr);
        fclose(output);
        return 1;
    }

    if(!output) {
        fputs("Fatal : Output file cannot be created\n",stderr);
        fclose(input);
        return 1;
    }

    if(compile(input,output) == NULL) {
        return 1;
    }

    return 0;
}
