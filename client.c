#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int n;

	char recvline[1024];
	while(1){
		fgets(recvline,1024,stdin);
		printf("You said: %s", recvline);
		memset(recvline,0,1024);
	}
}
