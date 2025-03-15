#include "commands.h"
#include <stdio.h>

const int MAX_BUFFER_SIZE = 1024;

void dump_file(char *path_file)
{
    FILE *file = fopen(path_file, "r");

    if(!file) 
    {
        printf("miraclecancodecat: %s: Нет такого файла или каталога\n", path_file);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    while(fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        fputs(buffer, file);
        printf("%s", buffer);
    }

    fclose(file);
}