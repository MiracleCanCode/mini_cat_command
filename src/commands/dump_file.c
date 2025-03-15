#include "commands.h"
#include <stdio.h>

void dump_file(char *path_file)
{
    FILE *file = fopen(path_file, "r");

    if(!file) 
    {
        printf("miraclecancodecat: %s: Нет такого файла или каталога\n", path_file);
        return;
    }

    char buffer[256];
    while(fgets(buffer, 256, file) != NULL) 
    {
        fputs(buffer, file);
        printf("%s", buffer);
    }

    fclose(file);
}