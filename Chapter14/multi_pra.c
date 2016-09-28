/*
 *practice for multi thread
*/

#include<stdio.h>
#include<pthread.h>
#include <unistd.h>


const int NUM=5;

void *print_msg(void *m)
{
	char *cp=(char *)m;
	int i=0;
	for(i=0;i<NUM;++i)
	{
		printf("%s",cp);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}


int main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,print_msg,(void *)"hello");
	pthread_create(&t2,NULL,print_msg,(void *)"house\n");	


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);	


	printf("\n");
}	
