#include <stdio.h>
#include "commands.h"

#define COPY_FILE_DATA_TEXT " -from [ФАЙЛ] -to [ФАЙЛ] скопировать откуда - куда\n"
#define READ_COMMAND_TEXT " -r/-R [ФАЙЛ] чтение файла и вывод на стандартный вывод\n"
#define REMARK_TEXT  "Использование: ./bin/isacat [ПАРАМЕТР] [ФАЙЛ]\n"\
"Если комманда не задана, то читает стандартный ввод\n\n"
#define SEARCH_COMMAND_TEXT " -s [ФАЙЛ] -w [СЛОВО] найти слово в файле\n"

void help(void)
{
   printf("%s", REMARK_TEXT); 
   printf("%s", COPY_FILE_DATA_TEXT);
   printf("%s", READ_COMMAND_TEXT);
   printf("%s", SEARCH_COMMAND_TEXT);
}