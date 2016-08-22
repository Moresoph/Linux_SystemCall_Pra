/*name setecho.c
 *usage setecho.o [y|n]
 *changed the echo state
 */
#include<stdio.h>
#include<termios.h>
#include<stdlib.h>

#define oops(s,x) { perror(s);exit(x);}

void main(int ac, char* av[])
{
	if( 1==ac)
	{
		exit(0);
	}
	
	struct termios info;
	if(tcgetattr(0,&info) == -1)
	{
		oops("tcgetattr",1);	
	}
	if( 'y' == av[1][0])
	{
		info.c_lflag |= ECHO;
	}	
	else if('n'==av[1][0])
	{
		info.c_lflag &=~ECHO;
	}
	
	if( tcsetattr(0,TCSANOW,&info) == -1 )
	{
		oops("tcsetattr",2);
	}	
}
