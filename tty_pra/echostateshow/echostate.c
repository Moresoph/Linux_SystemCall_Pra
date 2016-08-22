#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

void main()
{
	struct termios info;
	int rv;

	rv = tcgetattr(0,&info);

	if(-1==rv)
	{
		perror("tcgetattr");
		exit(1);
	}

	if(info.c_lflag&ECHO)
	{
		printf("echo is on\n");
	}
	else
	{
		printf("echo is off\n");
	}

}
