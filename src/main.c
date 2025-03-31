#include <string.h>
#include <stdio.h>
#include "commands.h"
#include "flags.h"
#define MAX_BUFFER_SIZE 1024
#define INCORRECT_ARG_ERR "isacat: Некоректная форма аргумента %s\n"
#define VIEW_ALL_ARGS_TEXT "isacat: Для просмотра доступных комманд запустите программу с флагом %s\n"

static int process_print_file(char** argv, const int argc, int i)
{
  const char* path_file = argv[i + 1];
  print_file(path_file);
}

static void  process_zero_args(char** argv, const int argc)
{
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), stdin))
    {
      fputs(buffer, stdout);
    }
}

static int process_overwrite_file(char** argv, const int argc, int i)
{
    const char* from_path_file = argv[i + 1];
    if (i + 2 < argc && strcmp(argv[i + 2], OVERWRITE_FILE_TO_FLAG) == 0)
    {
       const char* to_path_file = argv[i + 3];
       overwrite_file(from_path_file, to_path_file);
       return 0;
    }
    printf(INCORRECT_ARG_ERR, OVERWRITE_FILE_TO_FLAG);
    return 1;
}

static int process_find_text_in_file(char** argv, const int argc, int i)
{
    const char* path_file = argv[i + 1];
    if (i + 2 < argc && strcmp(argv[i + 2], FIND_TEXT_FLAG) == 0)
    {
        const char* text = argv[i + 3];
        find_text_in_file(path_file, text);
        return 0;
    }
    printf(INCORRECT_ARG_ERR, FIND_TEXT_FLAG);
    return 1;
}

static int process_copy_file(char** argv, const int argc, int i)
{
   const char* copy_path = argv[++i];
   if(i + 2 < argc && strcmp(argv[i+2], TO_COPY_FLAG) == 0)
   {
        const char* dest_path = argv[i+3];
        copy_file(copy_path, dest_path);
        return 0;
    }
    printf(INCORRECT_ARG_ERR, TO_COPY_FLAG);
    return 1;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        process_zero_args(argv, argc);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], HELP_FLAG) == 0) 
            print_help();

        if ((strcmp(argv[i], PRINT_FILE_FLAG) == 0) && i + 1 < argc)
        {
            if(process_print_file(argv, argc, i) == 0)
                return 0;
            return 1;
        }

        if (strcmp(argv[i], OVERWRITE_FROM_FLAG) == 0 && argc > 4)
        {
           if(process_overwrite_file(argv, argc, i) == 0)
               return 0;
           return 1;
        }

        if (strcmp(argv[i], FILE_FOR_FIND_TEXT_FLAG) == 0 && argc > 4)
        {
            if(process_find_text_in_file(argv, argc, i) == 0)
                return 0;
            return 1;
        }

        if (strcmp(argv[i], FROM_COPY_FLAG) == 0 && argc > 4)
        {
            if(process_copy_file(argv, argc, i) == 0)
                return 0;
            return 1;
        }

        print_help();
        return 0;
    }

    return 0;
}
