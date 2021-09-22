build/main: build/main.o build/input.o build/socket.o
	gcc -o build/main build/main.o build/input.o build/socket.o
build/main.o: main.c
	gcc -c -o build/main.o main.c 
build/input.o: input.c input.h
	gcc -c -o build/input.o input.c
build/socket.o: socket/socket.c socket/socket.h
	gcc -c -o build/socket.o socket/socket.c
