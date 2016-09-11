#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<execute.h>
#include<signal.h>
void execute(char* arglist[])
{
	int pid        = 0 ;
	int exitstatus = 0 ;
	pid = fork();
	if(0 == pid)
	{
		printf("child progress\n");
		int i=0;
		for(i=0;arglist[i]!=NULL;++i)
		{
			printf("in the pid = 0 arglist[%d] is ",i);
			printf(arglist[i]);
			printf("     \n");
		}
		printf("enter into execvp");
		execvp(arglist[0],arglist);
		perror("execvp failed");
		exit(1);
	}
	else if(-1 == pid)
	{
		perror("fork failed");
		exit(2);
	}
	else
	{
		wait(&exitstatus);
		printf("child pid is %d exit number is %d\n",pid,exitstatus);
		printf("high8 is %d,bit_7 is %d,low_7 is %d\n",exitstatus>>8,exitstatus&0X8f,exitstatus&0x7f);
	}

}
