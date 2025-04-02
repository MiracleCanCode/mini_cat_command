#include <stdio.h>
#define BUFFER_SIZE 4096

void copy_file(const char* source_path, const char* dest_path)
{
    FILE* dest_file = fopen(dest_path, "w");
    FILE* source_file = fopen(source_path, "r");
    if(dest_file == NULL || source_file == NULL)
        perror("isacat: dest or source file not found: ");
    
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, sizeof(buffer), source_file) != NULL)
        fputs(buffer, dest_file);
        
    fclose(source_file);
    fclose(dest_file);
}
