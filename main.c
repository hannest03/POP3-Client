#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "socket/socket.h"

int main(){

	//Connect to POP3 server
	pop_connect();


	//USERNAME
	char *username = readUsername();

	if(pop_sendCommand(username)==NULL){
		
		printf("Fehler mit dem Benutzernamen!\n");
		free(username);
		exit(-1);

	}
	free(username);

	//PASSWORD
	char *password = readPassword();

	if(pop_sendCommand(password)==NULL){

		printf("Fehler mit dem Passwort!\n");
		free(password);
		exit(-1);

	}
	free(password);

	//LIST / RERTR
	while(1){


		char *mail = getMail();

		if(mail==NULL){

			break;

		}

		char *ret = pop_sendCommand(mail);
		free(mail);

		if(ret == NULL){

			printf("Konnte keine Mail lesen!\n");
			continue;

		}
		printf("%s\n",ret);
		free(ret);
		

	}


	pop_close();


	return 0;

}
