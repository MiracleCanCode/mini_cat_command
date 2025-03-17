#include <string.h>
#include <stdio.h>
#include "commands.h"

const int MAX_BUFFER_SIZE = 1024;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("isacat: Для просмотра доступных комманд введите комманду --help\n");
        return 1;
    }

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0) 
        {
            help();
            return 0;
        }

        if ((strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-R") == 0) && i + 1 < argc)
        {
            char *path_file = argv[i + 1];
            dump_file(path_file);
            return 0;
        }

        if (argc == 1)
        {
            char buffer[MAX_BUFFER_SIZE];
            while (fgets(buffer, sizeof(buffer), stdin))
            {
                fputs(buffer, stdout);
            }
            return 0;
        }

        if (strcmp(argv[i], "-from") == 0 && argc > 4)
        {
            char *from_path_file = argv[i + 1];
            if (i + 2 < argc && strcmp(argv[i + 2], "-to") == 0)
            {
                char *to_path_file = argv[i + 3];
                insert_file_data(from_path_file, to_path_file);
                return 0;
            }
            else
            {
                printf("isacat: Некоректная форма аргумента -to\n");
                return 1;
            }
        }

        if (strcmp(argv[i], "-s") == 0 && argc > 4)
        {
            char *path_file = argv[i + 1];
            if (i + 2 < argc && strcmp(argv[i + 2], "-w") == 0)
            {
                char *text = argv[i + 3];
                search_text_in_file(path_file, text);
                return 0;
            }
            else
            {
                printf("isacat: Некоректная форма аргумента -w\n");
                return 1;
            }
        }
        printf("isacat: Аргумент не найден: %s\nisacat: Для просмотра доступных аргументов запустите isacat с флагом --help\n", argv[i + 1]);
        return 1;
    }

    return 0;
}
