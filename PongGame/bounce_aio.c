#include<string.h>
#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include<aio.h>

#define MESSAGE "O"
#define BLANK "      "

struct aiocb kbcbuf;

const int GAP_TIME = 1;
int done = 0;
int row = 5;
int col = 0;
int dir = 1;
const int max_col = 10;

void on_alarm(int signum)
{
	signal(SIGALRM,on_alarm);
	alarm(GAP_TIME);
	mvaddstr(row,col,BLANK);
	col+=dir;
	mvaddstr(row,col,MESSAGE);
	refresh();	
	if(col>max_col&&dir>0) {	dir =0 -dir;}
	if(col<=0&&dir<0) { dir = 0 - dir ; }
}

void setup_aio()
{
	static char input[1];
	bzero( (char *)&kbcbuf , sizeof(struct aiocb) );
	kbcbuf.aio_fildes = 0;
	kbcbuf.aio_buf = input;
	kbcbuf.aio_nbytes = 1;
	kbcbuf.aio_offset = 0;

	kbcbuf.aio_sigevent.sigev_notify=SIGEV_SIGNAL;
	kbcbuf.aio_sigevent.sigev_signo = SIGIO;
}

void on_input()
{
	int c =0 ;
	char *cp = (char *)kbcbuf.aio_buf;
	if(aio_error(&kbcbuf) != 0) { perror("reading faiiled");}
	else
	{
		if( aio_return(&kbcbuf) == 1)
		{
			c = *cp;
			if(c=='Q')
				done = 1;
			else if ( c == ' ')
				dir = -dir;
		}
	}
	aio_read(&kbcbuf);
}
void main()
{
	initscr();
	crmode();
	noecho();
	clear();

	signal(SIGIO,on_input);
	setup_aio();
	aio_read(&kbcbuf);

	signal(SIGALRM,on_alarm);
	alarm(GAP_TIME);	

	mvaddstr(0,0,"begin");
	while(!done)
	{
		pause();
	}
	endwin();
}
