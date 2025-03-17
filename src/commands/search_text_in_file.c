#include <stdio.h>
#include "commands.h"
#include <string.h>
#define MAX_BUFFER_SIZE 1024

void search_text_in_file(char *file, char *text)
{
    FILE *inputFile = fopen(file, "r");

    if(!inputFile)
    {
        printf("isacat: Такого файла не существует: %s\n", file);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int str_count = 0;
    while(fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        str_count++;
        if(strstr(buffer, text))
        {
            printf("строка %d: %s", str_count, buffer);
            return;
        }
    }
    printf("iscat: %s: Слово не найдено\n",text);
    fclose(inputFile);
}