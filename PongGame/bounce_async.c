#include<stdio.h>
#include<termios.h>
#include<curses.h>
#include<signal.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define PingPong "O"
#define BLANK "     "
#define max_col 20
#define cnt_odd "odd"
#define cnt_even "even"
FILE *ftp = NULL;
int GAP_TIME    = 1;
int dir         = 2;
int done        = 0;
int col         = 5;
int row         = 20;
int alarm_count = 0;


/*
 *install a handler,tell kernel who to notify on input
 *and enable signals
 */
void enable_kbd_signals()
{
	fcntl(0,F_SETOWN,getpid());
	int fd_flags = 0;
	fd_flags=fcntl(0,F_GETFL);
	fcntl(0,F_SETFL,(fd_flags|O_ASYNC|O_NDELAY));
}
/*
 *handler of signal SIGIO
 */
void on_input(int signum)
{
	/****
	static int on_input_count = 0;
	on_input_count++;
	if(on_input_count>100000) on_input_count = 0;
	char buffer_on[100];
	sprintf(buffer_on,"%d",on_input_count);		
	mvaddstr(15,0,"                 ");
	mvaddstr(15,0,buffer_on);

	static int k =0;
	char buffer[100];
	mvaddstr(13,0,"                     ");
	mvaddstr(14,0,"                     ");
	mvaddstr(13,0,"before c=getch()");
	int c=getch();
	if(c!=EOF)
	{
		++k;
		sprintf(buffer,"%c",c);
		mvaddstr(k,0,buffer);
	}
	else
	{
		mvaddstr(12,0,"            ");
		mvaddstr(12,0,"c = EOF");
	}
	mvaddstr(13,0,"                  ");
	mvaddstr(14,0,"after c=getch()");
	if(k>5)
	{
		k=0;
	}
	if('Q'==c)
	{
		done = 1;
		mvaddstr(7,0,"done changed");
	}	
	else if(' '==c)
	{
		dir = -dir;
	}
	****/
	static int cnt = 0;
	fprintf(ftp,"receive SIGIO signal %d\n",++cnt);	
	fflush_unlocked(ftp);
	mvaddstr(16,0,"       ");
	if(cnt%2==0)
		mvaddstr(16,0,cnt_odd);
	else
		mvaddstr(16,0,cnt_even);
}

/*
 *handler of signal SIGALARM
 */
void on_alarm(int signum)
{
	alarm_count++;
	signal(SIGALRM,on_alarm);
	alarm(GAP_TIME);
	mvaddstr(row,col,BLANK);
	col+=dir;
	mvaddstr(row,col,PingPong);
//	refresh();
	
	if(col>max_col&&dir>0)
	{
		dir = 0 - dir;
	}
	if(col<=0&&dir<0)
	{
		dir = 0 -dir;
	}	
}

int main()
{
	if( ( ftp = fopen("kk.txt","a") ) < 0 )
	{
		perror("kk.txt");
		exit(1);
	}

	initscr();
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_cc[VMIN]=1;
	tcsetattr(0,TCSANOW,&ttystate);

	echo();
	clear();

	struct sigaction newhandler;
	newhandler.sa_handler=on_input;
	newhandler.sa_flags=SA_RESTART;
	sigset_t blocked;
	sigemptyset(&blocked);
	sigaddset(&blocked,SIGALRM);
	newhandler.sa_mask=blocked;
	if(sigaction(SIGIO,&newhandler,NULL) == -1)
	{
		perror("sigacion");
		return -1;
	}
	enable_kbd_signals();

	signal(SIGALRM,on_alarm);
	alarm(GAP_TIME);

	int while_count = 0;
	refresh();
	while(!done)	
	{
/*********		
 		++while_count;
		if(while_count>100000) while_count = 0;
		if(alarm_count>10000) alarm_count  = 0;
		char buffer[100];
		sprintf(buffer,"%d",while_count);
		mvaddstr(9,0,"                      ");
		mvaddstr(9,0,buffer);
		char buffer1[100];
		sprintf(buffer1,"%d",alarm_count);	
		mvaddstr(10,0,"                     ");
		mvaddstr(10,0,buffer1);  	
		refresh();
******/
		pause();		
	}
	mvaddstr(1,0,"out of while");
	refresh();
	endwin();
	printf("out of while 111111");
	return 0;
}

