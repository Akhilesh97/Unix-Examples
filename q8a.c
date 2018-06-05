#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
        pid_t pid;
        if((pid = fork()) < 0)
                printf("Error\n");
        else if(pid > 0){
                printf("Child is %d Parent process id %ld",pid ,(long)getppid);
                printf("Parent killed\n");
                exit(0);
        }
        umask(0);
        if(chdir("/") < 0)
                printf("Eror\n");
        if(setsid()<0){
                printf("Error\n");
        }

}
