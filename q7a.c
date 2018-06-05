#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	if((pid = fork()) < 0)
		printf("Fork error\n");
	else if(pid == 0){
		if((pid = fork()) < 0)
			printf("Fork error");
		else if(pid > 0)
			exit(0);
		sleep(2);
		printf("Second child, parent process id = %ld",(long)(getppid));
		
		exit(0);
	}
	if((waitpid(pid,NULL,0))!=pid)
		printf("Error\n");
	exit(0);
}
