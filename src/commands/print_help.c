#include <stdio.h>
#include "commands.h"

#define COPY_FILE_DATA_TEXT " -from [ФАЙЛ] -to [ФАЙЛ] скопировать откуда - куда\n"
#define READ_COMMAND_TEXT " -r [ФАЙЛ] чтение файла и вывод на стандартный вывод\n"
#define REMARK_TEXT  "Использование: ./bin/isacat [ПАРАМЕТР] [ФАЙЛ]\n"\
"Если комманда не задана, то читает стандартный ввод\n\n"
#define SEARCH_COMMAND_TEXT " -s [ФАЙЛ] -w [СЛОВО] найти слово в файле\n"
#define PRINT_INFO_FILE_TEXT " -info [ФАЙЛ] вывести информацию о файле"

void print_help(void)
{
   printf(REMARK_TEXT); 
   printf(COPY_FILE_DATA_TEXT);
   printf(READ_COMMAND_TEXT);
   printf(SEARCH_COMMAND_TEXT);
   puts(PRINT_INFO_FILE_TEXT);
}
