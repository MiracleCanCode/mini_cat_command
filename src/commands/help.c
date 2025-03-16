#include <stdio.h>
#include "commands.h"

#define COPY_FILE_DATA_TEXT "  -from [ФАЙЛ] -to [ФАЙЛ] ---- здесь мы указываем -from [ФАЙЛ](это то какой файл мы хотим скопировать) -to [ФАЙЛ](это то в какой файл мы хотим вставить скопированное)"
#define READ_COMMAND_TEXT "  -r/-R [ФАЙЛ] - чтение файла и вывод на стандартный вывод\n"
#define REMARK_TEXT  "Использование: ./bin/isacat [ПАРАМЕТР] [ФАЙЛ]\nЕсли комманда не задана, то читает стандартный ввод\n\n"

void help(void)
{
   printf("%s", REMARK_TEXT); 
   printf("%s", READ_COMMAND_TEXT);
   printf("%s\n", COPY_FILE_DATA_TEXT);
}