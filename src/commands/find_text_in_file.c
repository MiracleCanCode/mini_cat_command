#include <stdio.h>
#include "commands.h"
#include <string.h>
#define MAX_BUFFER_SIZE 1024

void find_text_in_file(const char* file, const char* text)
{
    FILE *inputFile = fopen(file, "r");

    if(!inputFile)
    {
        perror("isacat:");
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
            fclose(inputFile);
            return;
        }
    }

    printf("isacat: %s: Слово не найдено\n",text);
    fclose(inputFile);
}
