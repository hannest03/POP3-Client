#include <stdio.h>
#include "socket/socket.h"

#include "input.h"

int main(){
	char* username = getMail();
	printf("%s",username);
}
