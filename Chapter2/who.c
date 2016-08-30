/*
 *who.c - works like the command 'who';
 *target:to learn open,read,close system call
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<utmp.h>
#include<stdlib.h>

int show_info(struct utmp *utmp_buffer)
{
	if( NULL == utmp_buffer )
	{
		printf("invaild utmp\n");
		return -1;	
	}

	printf("%-8.8s",utmp_buffer->ut_user);
	printf("  ");
	printf("%-8.8s",utmp_buffer->ut_line);
	printf("  ");
	printf("\n");
}

int main()
{
	int utmp_fd = -1;
	if( -1 == (utmp_fd = open(UTMP_FILE,O_RDONLY)) )
	{
		perror(UTMP_FILE);
		exit(1);
	}	
	struct utmp utmp_current_record;
	int utmp_size = sizeof(utmp_current_record);
	while( read(utmp_fd,&utmp_current_record,utmp_size))
	{
		show_info(&utmp_current_record);	
	}
	if( 0!=close(utmp_fd ) )
	{
		perror(UTMP_FILE);
	}
	return 0;
}
