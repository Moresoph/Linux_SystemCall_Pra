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



const int utmp_arr_len=16;



int show_info(struct utmp *utmp_buffer)
{
	if( NULL == utmp_buffer )
	{
		printf("invaild utmp\n");
		return -1;	
	}
	if( utmp_buffer->ut_type == DEAD_PROCESS )
		return 0;
	if( utmp_buffer->ut_type != USER_PROCESS )
		return 0;
	printf("%-8.8s",utmp_buffer->ut_user);
	printf("  ");
	printf("%-8.8s",utmp_buffer->ut_line);
	printf("  ");
	printf("%-8.8s",utmp_buffer->ut_host);
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
	struct utmp utmp_current_record[utmp_arr_len];
	int read_size = 0;
	int utmp_size = sizeof(struct utmp);
	const int utmp_arr_size = utmp_size * utmp_arr_len;
	while(read_size =  read(utmp_fd,utmp_current_record,utmp_arr_size))
	{
		printf("read_size if %d\n",read_size);
		int total_num = read_size / utmp_size;
		int cur_num = 0;
		for( cur_num =0 ; cur_num < total_num ; ++cur_num)
		{
			show_info(&(utmp_current_record[cur_num]));	
		}
	}
	if( 0!=close(utmp_fd ) )
	{
		perror(UTMP_FILE);
	}
	return 0;
}
