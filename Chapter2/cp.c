/*
 *works like the shell command "cp"
 *Target:to learn these system-calls blow
 * creat , wirte 
 */

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_MAX 4096

int main(int ac,char *av[])
{
	if( ac != 3 )
	{
		fprintf(stderr,"usage:%s shource destination \n",*av);
		exit(1);
	}
	
	int in_fd   = -1;
	int out_fd  = -1;
	int n_chars = 0;
	char buf[BUFFER_MAX];

	if( -1 == (in_fd=open(av[1],O_RDONLY)) )
	{
		perror(av[1]);
		return -1;
	}	
	if( -1 == (out_fd=creat(av[2],0644)) )
	{
		perror(av[2]);
		return -1;
	}
	while( (n_chars=read(in_fd,buf,BUFFER_MAX)) > 0 )
	{
		while( write(out_fd,buf,n_chars) != n_chars )
		{
			perror(av[2]);
		}
	}	
	if( -1 == n_chars )
	{
		perror(av[1]);
	}
	if( -1==close(in_fd) || -1==close(out_fd) )
	{
		printf("close error\n");
		exit(1);
	}

	return 0;
}
