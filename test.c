#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <pthread.h>

//#include "dynamic_dump_stack.h"

#define INSDUMP_SYSCALL 359
#define RMDUMP_SYSCALL 360

extern int probe_remove(int pid);

//struct for dump mode
struct dumpmode_t{
	unsigned int mode;
};

//function to open fd and trigger kprobe
void* trigger(void* input){
	int fd;
	fd = open("/dev/null", O_RDWR);
	printf("using open to trigger kprobe\n");
	if(close(fd)<0){
		printf("could not open file......\n");
	}
	return 0;
}


int main(int argc, char *argv[]) {

	char symbolname[20];
	struct dumpmode_t mode_input;
	int ret = 0;
	int ret1 = 0;
	int ret2 = 0;
	int fd;
	int user_dumpmode;
	int user_dumpmodex;
	pthread_t dump_thread;

	printf("Enter dump stack mode = ");
	scanf("%d", &user_dumpmode);

	mode_input.mode = user_dumpmode;
	snprintf(symbolname, sizeof(char)*20, "%s", "sys_open");

	//syscall - INSDUMP , symbol name given is "sys_open"
	ret = syscall(INSDUMP_SYSCALL,symbolname, &mode_input);
	if(ret < 0){
		printf("Syscall INSDUMP error.... %d\n", ret);
		return -1;
	}
	printf("from main, dump id =  %d\n", ret);

	fd = open("/dev/null", O_RDWR);
	if(close(fd)<0){
		printf("could not open file......\n");
	}

	if(user_dumpmode==1){
	if(fork() == 0)
	{
		if(fork()==0){
			printf("child processes created....\n");
			//printf("Enter dump stack mode to check dumpstack ops for child processes = \n");
			//scanf("%d", &user_dumpmodex);
			user_dumpmodex=1;
			mode_input.mode = user_dumpmodex;
			snprintf(symbolname, sizeof(char)*20, "%s", "sys_open");
			ret2 = syscall(INSDUMP_SYSCALL,symbolname, &mode_input);
			if(ret2 < 0){
				printf("Syscall INSDUMP error 2.... %d\n", ret);
				return -1;
			}
			printf("from main, dump id (sec) =  %d\n", ret);
		}
		else{
			printf("do nothing..\n");
		}
		printf("from main, dump id =  %d\n", ret);
	}
}


pthread_create(&dump_thread,NULL, trigger, (void *) NULL);
pthread_join(dump_thread,NULL);

sleep(3);
ret1 = syscall(RMDUMP_SYSCALL,ret);
if(ret1 < 0){
	printf("could not remove dump stack..\n");
	return -1;
}
printf("Dump stack removed successfully for dump id = %d\n", ret);

// ret1 = syscall(RMDUMP_SYSCALL,ret2);
// if(ret2 < 0){
// 	printf("could not remove dump stack..\n");
// 	return -1;
// }
// printf("Dump stack removed successfully for dump id = %d\n", ret);
return 0;

//return 1;

}
