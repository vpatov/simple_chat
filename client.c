#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "net.h"

int main(int argc, char **argv)
{
	int sockfd, n;
	struct sockaddr_in servaddr;
	int rec_port;

	
	char recvline[1024];
	/*
	while(1){
		fgets(recvline,1024,stdin);
		printf("You said: %s", recvline);
		memset(recvline,0,1024);
	}
	*/

        if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	                err_sys("socket error");

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port   = htons(9020);        
        if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0)
	                err_quit("inet_pton error for %s", argv[1]);

        if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	                err_sys("connect error");

        while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
	                recvline[n] = 0;        /* null terminate */
		                if (fputs(recvline, stdout) == EOF)
 				                        err_sys("fputs error");
			        }
        if (n < 0)
	                err_sys("read error");

        exit(0);


}
