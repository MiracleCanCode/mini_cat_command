BASE_DIR_COMMAND=./src/commands/
FILES=./src/main.c ${BASE_DIR_COMMAND}dump_file.c ${BASE_DIR_COMMAND}help.c ${BASE_DIR_COMMAND}insert_file_data.c
PATH_TO_COMPIL=./bin/isacat
PATH_TO_LIB=./src/lib

build:
	@mkdir -p bin
	gcc ${FILES} -o ${PATH_TO_COMPIL} -I ${PATH_TO_LIB}
