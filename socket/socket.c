#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#include <ctype.h>

#include "socket.h"

#define PORT 110

int socket_id = -1;

void error(char* message){
	perror(message);
	exit(1);
}

char* trimwhitespace(char *str){
  char *end;
  while(isspace((unsigned char)*str)) str++;
  if(*str == 0)
    return str;
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;
  end[1] = '\0';
  return str;
}

int checkResponseCode(char* message, char* expectedResponse){
	int ret = 1;
	char* code = malloc(strlen(message) + 1); 
	strcpy(code, message);
	code = strtok(code, "\n");
	code = strtok(code, " ");
	code = trimwhitespace(code);
	if(strcmp(code, expectedResponse) == 0)
		ret = 0;
	return ret;
}

void pop_connect(){
	socket_id = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_id < 0){
		error("Fehler beim erstellen des Sockets\n");
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = connect(socket_id, (struct sockaddr*) &addr, sizeof(addr));
	if(ret != 0){
		error("Konnte keine Verbindung zum POP3 Server aufbauen.\n");
	}
	printf("Verbindung mit dem POP3 Server aufgebaut!\n");
	
	// Schauen ob Verbingung erfolgreich war
	char buffer[1000];
	memset(buffer, 0, sizeof(buffer));
 	recv(socket_id, buffer, sizeof(buffer), 0);
	if(checkResponseCode(buffer, "+OK") != 0){
		error("Fehler beim Verbinden mit dem POP3 Server (wrong response)!\n");
	}
}

void pop_close(){
	close(socket_id);
}

char* pop_sendCommand(char* command){

	send(socket_id, command, strlen(command), 0);

	int size_buffer = sizeof(char) * 1000;
	char* buffer = malloc(size_buffer);
	memset(buffer, 0, size_buffer);
 	int ret = recv(socket_id, buffer, size_buffer, 0);

	if(checkResponseCode(buffer, "+OK") != 0){
		return NULL;
	}
	return buffer;
}
