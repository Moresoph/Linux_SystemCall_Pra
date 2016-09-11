#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<execute.h>
const int MAXARGS = 20;
const int ARGLEN  = 100;

char* makestring(char *buf)
{
	char *ret;
	int lenth=strlen(buf);
	printf("int makestring\n");
	printf("strlen(%s) is %d\n",buf,lenth);
	buf[lenth-1]='\0';
	printf(buf);
	ret=malloc(lenth);
	if(NULL==ret)
	{
		perror("malloc");
		exit(1);
	}	
	strcpy(ret,buf);
	return ret;
}
int main()
{
	char *arglist[MAXARGS+1];
	int numargs = 0;
	char argbuf[ARGLEN];	
	while(numargs<MAXARGS)
	{
		printf("Arg[%d]?",numargs);
		if( fgets(argbuf,ARGLEN,stdin) && *argbuf != NULL )
		{
			arglist[numargs]=makestring(argbuf);
			++numargs;
		}	
		else
		{
			if(numargs>0)
			{
				arglist[numargs]=NULL;
				int i=0;
				execute(arglist);
				for(i=0;i<numargs;++i)
				{
					printf("arglist[%d] is ",i);
					printf(arglist[i]);
					printf("\n");
					free(arglist[i]);
				}
				numargs=0;
			}
		}
	}
}


