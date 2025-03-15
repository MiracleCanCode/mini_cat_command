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
        if((strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-R") == 0) && i+1 < argc)
        {
            char *path_file = argv[i+1];
            dump_file(path_file);
        }
    }
    return 0;
}