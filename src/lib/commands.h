#ifndef COMMANDS_H
#define COMMANDS_H

void print_file(const char *path_file);
void print_help(void);
void overwrite_file(const char *from, const char *to);
void find_text_in_file(const char *file, const char *text);
void copy_file(const char *source_path, const char *dest_path);

#endif
