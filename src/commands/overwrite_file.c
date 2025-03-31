#include "commands.h"
#include <stdio.h>

#define SUCCESSFULY_COPY_TEXT "Вставка завершен успешно!\n"

#define MAX_COPY_BUFFER_SIZE 1024

void overwrite_file(const char* from, const char* to)
{
    FILE* copy_file = fopen(from, "r");

    if (!copy_file) 
    {
        perror("isacat:");
    }

    FILE* insert_file = fopen(to, "r+");

    if(!insert_file)
    {
        perror("isacat:");
    }

    char copy_buffer[MAX_COPY_BUFFER_SIZE];
    while(fgets(copy_buffer, sizeof(copy_buffer), copy_file))
    {
        fputs(copy_buffer, insert_file);
    }

    fclose(copy_file);
    fclose(insert_file);

    printf(SUCCESSFULY_COPY_TEXT);
}
