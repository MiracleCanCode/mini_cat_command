BASE_DIR_COMMAND=./src/commands/
FILES=./src/main.c ${BASE_DIR_COMMAND}find_text_in_file.c ${BASE_DIR_COMMAND}print_file.c ${BASE_DIR_COMMAND}print_help.c ${BASE_DIR_COMMAND}overwrite_file.c ${BASE_DIR_COMMAND}copy_file.c ${BASE_DIR_COMMAND}print_info_file.c
PATH_TO_COMPIL=./bin/isacat
PATH_TO_LIB=./src/lib

build:
	@mkdir -p bin
	gcc ${FILES} -o ${PATH_TO_COMPIL} -I ${PATH_TO_LIB}
