#include <stdio.h>
#include "socket/socket.h"

int main(){
	pop_connect();

	char* res;

	res = pop_sendCommand("USER kali\n");
	if(res == NULL){
		printf("NULL\n");
	}else{
		printf("%s\n", res);
	}
	res = pop_sendCommand("PASS kali\n");
	if(res == NULL){
		printf("NULL\n");
	}else{
		printf("%s\n", res);
	}
	res = pop_sendCommand("LIST\n");
	if(res == NULL){
		printf("NULL\n");
	}else{
		printf("%s\n", res);
	}

	pop_close();
}
