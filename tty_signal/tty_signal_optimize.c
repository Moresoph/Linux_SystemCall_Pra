#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<string.h>

#define QUES "do you want another transaction?"
#define TRIES 10 
#define SLEEPTIME 1 
#define BEEP printf("time out try again")

int tty_mod(int);

void ctrl_c_handler(int sig_num)
{
	printf("entered in signal SIGINT event\n");
	tty_mod(0);
	exit(1);
}

int tty_mod(int how)
{
	static struct termios origianl_mode;
	static int original_flags;
	static int stored = 0;
	int res=0;
	if(1 == how)
	{
		original_flags=fcntl(0,F_GETFL);
		res = tcgetattr(0,&origianl_mode);
		stored = 1;
	}
	else if(1 == stored)
	{
		fcntl(0,original_flags);
		res = tcsetattr(0,TCSANOW,&origianl_mode);
	}
	return res;
}

char get_ok_char()
{
	char temp =0;
	while( (temp=getchar()) != EOF && strchr("YyNn",temp) == NULL )
	{
		printf("you put %c in,not right\n",temp);
	}
	return temp;	
}

int get_response(char *question)
{
	int k=TRIES;
	printf("%s (y/n)",question);
	fflush(stdout);
	while(1)
	{
		sleep(SLEEPTIME);
		switch( get_ok_char() )
		{
			case 'y':
			case 'Y':return 0;
			case 'n':
			case 'N':return 1;
			case EOF:printf("k=%d\n",k); 
		}
		if( --k <= 0)
		{
			BEEP;
			return 1;
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
void set_nodelay_mode()
{
	int termflags=fcntl(0,F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0,F_SETFL,termflags);
}
void main()
{
	signal(SIGINT,ctrl_c_handler);
	tty_mod(1);	
	set_nodelay_mode();
	set_cr_noecho_mode();
	int response = 0; 
	response = get_response(QUES);
	tty_mod(0);
	printf("\n");
	return ;
}
