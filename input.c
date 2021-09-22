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

	printf("Username: ");

	char *username = readInput();

	char *command = concat(USER,username);

	free(username);

	return command;	


}

char* readPassword(){

	printf("Password: ");
	
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

char* readRetrN(int mail){

	char mai[3];
       	mai[0] = (mail+'0');
	mai[1] = '\n';
	mai[2] = 0;

	char *retrN = concat(RETRN, mai);
	
	return retrN;	

}


char* getMail(){

	char* list = "List\n";
        char* exit = "Exit\n";

	printf("List of mails with List,\nSpecific mail with number: ");

	while(1){
		char* option = readInput();

		if(!strcmp(option,list)){

			return readList();

		}else	

		if(atoi(option)){
			int mail = atoi(option);
			return readRetrN(mail);

		}else

		if(!strcmp(option,exit)){

			return NULL;

		}else
			printf("Konnte den Befehl nicht erkennen\n");
	}

}
