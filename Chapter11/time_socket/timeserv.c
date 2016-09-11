#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<string.h>

const int HOSTLEN = 256;
const int PORTNUM = 13000;

int main(int ac,char* av[])
{
	/*
	 *Step1: ask kernel for a socket
	 */
	int sock_id = -1;
	sock_id=socket(PF_INET,SOCK_STREAM,0);
	if(-1 == sock_id)
	{
		perror("open socket");
	}
	/*
	 *Step2: bind address to soket.
	 *Adress is host , port;
	 */
	char hostname[HOSTLEN];
	gethostname( hostname,HOSTLEN);

	struct hostent *hp=NULL;
	hp = gethostbyname(hostname);

	struct sockaddr_in saddr;
	bzero( (void *)&saddr,sizeof(saddr) );

	bcopy( (void *) ((hp->h_addr_list)[0]), (void *)&saddr.sin_addr,hp->h_length);
	saddr.sin_port = htons(PORTNUM);
	saddr.sin_family= AF_INET;	
	if( bind( sock_id,(struct sockaddr *)&saddr,sizeof(saddr) ) != 0)
	{
		perror("bind socket");
	}
	/*Step3:
	 *
	 */
	if( listen(sock_id,1) != 0)
	{
		perror("listen");
	}
	FILE * sock_fp =NULL;
	int sock_fd;
	while(1)
	{
		 sock_fd=accept(sock_id ,NULL, NULL);
		 printf("Wow!got a call!\n");
		 if(-1==sock_fd)
		 {
			perror("accept");
		 }

		 sock_fp =fdopen(sock_fd,"w");
		 if(sock_fp==NULL)
		 {
			perror("fdopen");	
		 }
		 time_t thetime = time(NULL);
		 fprintf( sock_fp, "The time is ");
		 fprintf( sock_fp, "  %s  ",ctime(&thetime));
		 fclose( sock_fp );
	}
}
