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
	move(1,1);
	addstr("ENTER ALARM_HANDLER,signal_num ");
	refresh();
}


int main()
{
	int i =0;
	int k =dir;
	initscr();
	clear();
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
		alarm(GAP_TIME);	
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

