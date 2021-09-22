build/main: build/main.o
	gcc -o build/main build/main.o
build/main.o: main.c
	gcc -c -o build/main.o main.c
