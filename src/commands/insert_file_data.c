#include "commands.h"
#include <stdio.h>

#define SUCCESSFULY_COPY_TEXT "Копирование завершено успешно!\n"
#define ERROR_EXIST_INSERT_FILE "isacat: %s: Файла для вставки не существует\n"
#define ERROR_EXIST_COPY_FILE "isacat: %s: Нет такого файла или каталога из которого вы хотите скопировать данные\n"

const int MAX_COPY_BUFFER_SIZE = 1024;

void insert_file_data(char *from, char *to)
{
    FILE *copy_file = fopen(from, "r");

    if (!copy_file) 
    {
        printf(ERROR_EXIST_COPY_FILE, from);
        return;
    }

    FILE *insert_file = fopen(to, "w");

    if(!insert_file)
    {
        printf(ERROR_EXIST_INSERT_FILE, to);
        return;
    }

    char copy_buffer[MAX_COPY_BUFFER_SIZE];
    while(fgets(copy_buffer, sizeof(copy_buffer), copy_file))
    {
        fputs(copy_buffer, insert_file);
    }

    fclose(copy_file);
    fclose(insert_file);

    printf("%s", SUCCESSFULY_COPY_TEXT);
}