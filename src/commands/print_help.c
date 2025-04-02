#include <stdio.h>
#include "commands.h"

#define COPY_FILE_DATA_TEXT " -from [ФАЙЛ] -to [ФАЙЛ] скопировать откуда - куда"
#define READ_COMMAND_TEXT " -r [ФАЙЛ] чтение файла и вывод на стандартный вывод"
#define REMARK_TEXT  "Использование: ./bin/isacat [ПАРАМЕТР] [ФАЙЛ] "\
"Если комманда не задана, то читает стандартный ввод\n"
#define SEARCH_COMMAND_TEXT " -s [ФАЙЛ] -w [СЛОВО] найти слово в файле"
#define PRINT_INFO_FILE_TEXT " -info [ФАЙЛ] вывести информацию о файле"

void print_help(void)
{
   puts(REMARK_TEXT); 
   puts(COPY_FILE_DATA_TEXT);
   puts(READ_COMMAND_TEXT);
   puts(SEARCH_COMMAND_TEXT);
   puts(PRINT_INFO_FILE_TEXT);
}
