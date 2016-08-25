#include<curses.h>
#include<stdio.h>

int main()
{
	initscr();
	
	clear();
	move(10,20);
	addstr("Hello,world");
	move(LINES-1,0);	
	addstr(:
//	refresh();
	getch();
	endwin();
	return 0;
}



