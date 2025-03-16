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
            return 0;
        }
        if((strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-R") == 0) && i+1 < argc)
        {
            char *path_file = argv[i+1];
            dump_file(path_file);
            return 0;
        }
        if(argc == 1)
        {
            const int MAX_BUFFER_SIZE = 1024;
            char buffer[MAX_BUFFER_SIZE];
            while (fgets(buffer, sizeof(buffer), stdin))
            {
                fputs(buffer, stdout);
            }
            return 0;
        }
        if((strcmp(argv[i], "-from") == 0) && argc == 5)
        {
            char *from_path_file = argv[i+1];
            if(strcmp(argv[i+2], "-to") == 0)
            {
                char *to_path_file = argv[i+3];
                insert_file_data(from_path_file, to_path_file);  
            }
            return 0;
        }
    }
    return 0;
}