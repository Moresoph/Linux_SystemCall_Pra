#include<stdio.h>

int main()
{
	char *arg[3];
	arg[0]="ls";
	arg[1]="-l";
	arg[2]=NULL;
	execvp("ls",arg);
}
