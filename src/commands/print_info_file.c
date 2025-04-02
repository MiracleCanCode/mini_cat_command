#include <stdio.h>
#include "commands.h"
#include <sys/stat.h>
#include <time.h>

void print_info_file(const char* source_file)
{
    struct stat file_info;

    if(stat(source_file, &file_info) != 0)
    {
        perror("Error: geting info file");
        return;
    }
    
    printf("File size %ld bytes\n", file_info.st_size);
    printf("Time last access: %s", ctime(&file_info.st_atime));
    printf("Time last modify: %s", ctime(&file_info.st_mtime));
    printf("Owner ID: %u\n", file_info.st_uid);
}