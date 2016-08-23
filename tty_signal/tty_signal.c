#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#define QUES "do you want another transaction?"
int tty_mod(int how)
{
	static struct termios origianl_mode;
	int res=0;
	if(1 == how)
	{
		res = tcgetattr(0,&origianl_mode);
	}
	else
	{
		res = tcsetattr(0,TCSANOW,&origianl_mode);
	}
	return res;
}

int get_response(char *question)
{
	printf("%s (y/n)",question);
	while(1)
	{
		switch( getchar() )
		{
			case 'y':
			case 'Y':return 0;
			case 'n':
			case 'N':return 1;
			case EOF:return 1; 
		}
	}
}

void set_cr_noecho_mode()
{
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}
void main()
{
	tty_mod(1);	
	set_cr_noecho_mode();
	int response = 0; 
	response = get_response(QUES);
	tty_mod(0);
	printf("\n");
	return ;
}
