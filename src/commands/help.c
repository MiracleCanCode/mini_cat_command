#include <stdio.h>
#include "commands.h"

void help(void)
{
   char REMARK[] = "Использование: ./miraclecancodecat [ПАРАМЕТР] [ФАЙЛ]\nЕсли ФАЙЛ не задан или задан как -, то читает стандартный ввод\n\n";
   char READ_COMMAND_TEXT[] = "  -r/-R [ФАЙЛ] - чтение файла и вывод на стандартный вывод\n";
   printf("%s", REMARK); 
   printf("%s", READ_COMMAND_TEXT);
}