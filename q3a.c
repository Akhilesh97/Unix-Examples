#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc,char *argv[]){
	struct dirent *dir;
	DIR *dp;
	int fd,n;
	dp = opendir("./");
	if(dp){
		while(dir = readdir(dp)){
			fd = open(dir->d_name,O_RDWR,0777);
			n = lseek(fd,(off_t)0,SEEK_END);
			if(!n)
				unlink(dir->d_name);
		}
	}
}
