#include<curses.h>
#include<stdio.h>
#include<unistd.h>

#define GAP_TIME  (1)
#define SLEEP_TIME (3)
#define BLANK ("                             ")
int main()
{
	int i =0;
	initscr();
	clear();
	for(i=0; i< LINES ; ++i)
	{
		move(i , i+1);
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
		sleep(GAP_TIME);
		move(i,i+1);
		addstr(BLANK);
	}	
	endwin();
	return 0;
}

