#include<stdio.h>
#include<unistd.h>
#include<signal.h>

#define INPUTLEN 100

void inthandler(int s)
{
	static int i = 0;
	printf("Called with signal %d time is %d\n",s,i);
	sleep(2);
	printf("done handling signal %d time is %d\n",s,i++);
}
int main()
{
	struct sigaction newhandler;
	sigset_t blocked;
	char x[INPUTLEN];

	newhandler.sa_handler = inthandler;
	newhandler.sa_flags = SA_RESTART;
	
	sigemptyset(&blocked);	
	sigaddset(&blocked,SIGQUIT);
	newhandler.sa_mask=blocked;

	if( sigaction(SIGINT,&newhandler,NULL) == -1 )
	{
		perror("sigaction");
	}
	else
	{
		while(1)
		{
			fgets(x,INPUTLEN,stdin);
			printf("input: %s\n",x);
		}
	}
}
