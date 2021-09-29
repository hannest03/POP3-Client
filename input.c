#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *USER = "USER ";
const char *PASSWORD = "PASS ";
const char *LIST = "LIST ";
const char *RETR = "RETR ";
const char *LISTMAIL = "LIST\n";
const char *RETRN = "RETR ";

char* concat(const char *s1, const char *s2){

    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;

}




char* readInput(){

	char input[1000];
	fgets(input,1000,stdin);
	//input[strlen(input)-1]=0;

	char* retInput = malloc(sizeof(char) *strlen(input));
	strcpy(retInput, input);

	return retInput;
	

}


char* readUsername(){

	printf("Benutzername: ");

	char *username = readInput();

	char *command = concat(USER,username);

	free(username);

	return command;	


}

char* readPassword(){

	printf("Passwort: ");
	
	char *password = readInput();

	char *command = concat(PASSWORD,password);

	free(password);

	return command;
	
}

char* readList(){

	char *retList = malloc(sizeof(char) *strlen(LISTMAIL));
	strcpy(retList,LISTMAIL);

	return retList;
	

}

char* readRetrN(char *mail){

	char *retrN = concat(RETRN, mail);
	
	return retrN;	

}


char* getMail(){

	char* list = "List\n";
        char* exit = "Exit\n";

	printf("Liste von Mails mit List, Mail auslesen mit gewünschter Nummer: \n");

	while(1){
		char* option = readInput();

		if(!strcasecmp(option,list)){

			return readList();

		}else	

		if(atoi(option)){

			return readRetrN(option);

		}else

		if(!strcasecmp(option,exit)){

			return NULL;

		}else
			printf("Konnte den Befehl nicht erkennen\n");
	}

}
