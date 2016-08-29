#include<curses.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

#define GAP_TIME  (1)
#define SLEEP_TIME (3)
#define BLANK ("                             ")
#define dir 5
#define COLUMN_MAX 20
#define LINE_MAX   LINES

void ALARM_HANDLER(int signal_num)
{
	static int k =0;
	move(k,k);
	++k;
	if(k>10)
	{
		k=0;
	}
	addstr("ENTER ALARM_HANDLER,signal_num ");
	refresh();
}


int main()
{
	int i =0;
	int k =dir;
	initscr();
	clear();
	alarm(GAP_TIME);	
	while(1)
	{
		move(5, i+k);
		if(0==i%2)
		{
			standout();
		}
		addstr("OKOK,Just for fun");
		if(0==i%2)
		{
			standend();
		}
		refresh();	
		signal(SIGALRM,ALARM_HANDLER);
		pause();
		move(5,i+k);
		addstr(BLANK);
		i+=k;
		if(i>=COLUMN_MAX) 
		{
			k=0-dir;
		}
		if(i<=0)
		{
			k=dir;
		}
	}	
	endwin();
	return 0;
}

