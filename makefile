build/main: build/main.o build/socket.o
	gcc -o build/main build/main.o build/socket.o
build/main.o: main.c
	gcc -c -o build/main.o main.c
build/socket.o: socket/socket.c socket/socket.h
	gcc -c -o build/socket.o socket/socket.c
