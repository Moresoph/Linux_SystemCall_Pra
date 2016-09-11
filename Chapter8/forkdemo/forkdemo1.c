#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

const int exit_value=5;
const int delay_value=2;
void child_code(int delay)
{
	printf("child_code sleep %d \n",delay);
	sleep(delay);
	exit(5);
}
void parent_code(int childpid)
{
	int ret_wait = -1 ;
	printf("done waiting for %d. Wait returned :%d\n",childpid,ret_wait);
	wait(&ret_wait);
	int high_8 = -1;
	int low_7 = -1;
	int bit_7 = -1;
	high_8=ret_wait>>8;
	low_7=ret_wait&0x7F;
	bit_7=ret_wait&0x80;
	printf("high_8 is %d, low_7 is %d, bit_7 is %d\n",high_8,low_7,bit_7);
	return;
}

int main()
{
	int ret_from_fork=0;
	int mypid=0;
	mypid=getpid();
	printf("Before:my pid is %d\n",mypid);
	ret_from_fork=fork();
	if(ret_from_fork == -1)
	{
		perror("fork failed");
	}
	else if(0==ret_from_fork)
	{
		child_code(delay_value);
	}
	else
	{
		parent_code(ret_from_fork);
	}
	return 0;
}
