#include "net.h"
#define LISTENQ 100


int main(int argc, char **argv)
{

	int client_listenfd, connfd;

	struct sockaddr_in listen_addr, client_addr;
	socklen_t client_addrlen;
	
	client_listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&client_addr,sizeof(client_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(9020);

	bind(client_listenfd, (struct sockaddr *) &listen_addr, sizeof(listen_addr));
	listen(client_listenfd, LISTENQ);

	if ((connfd = accept(client_listenfd, (struct sockaddr *)  &client_addr, &client_addrlen)) < 0){
		if (errno == EINTR)
			return 0;
		else {
			printf("Error while trying to accept a connection: %s \n", strerror(errno));

		}
	}

	printf("Connected with client!\n");
}
