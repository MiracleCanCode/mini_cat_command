#include <string.h>
#include <stdio.h>
#include "commands.h"


int main(int argc, char *argv[])
{

    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], "--help") == 0) 
        {
            help();
        }
        if(strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-R") == 0)
        {
            dump_file("");
        }
    }
    return 0;
}