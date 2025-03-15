FILES=./src/main.c ./src/commands/dump_file.c ./src/commands/help.c
PATH_TO_COMPIL=./bin/miraclecancodecat
PATH_TO_LIB=./src/lib

build:
	@mkdir -p bin
	gcc ${FILES} -o ${PATH_TO_COMPIL} -I ${PATH_TO_LIB}