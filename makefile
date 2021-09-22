build/main: build/main.o build/input.o
	gcc -o build/main build/main.o build/input.o
build/main.o: main.c
	gcc -c -o build/main.o main.c 

build/input.o: input.c input.h
	gcc -c -o build/input.o input.c
