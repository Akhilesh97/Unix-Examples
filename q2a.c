#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	struct dirent *dir;
	struct stat filestat;
	DIR *dp;
	dp = opendir("./");
	if(dp){
		printf("Inode\tMode\tUserID\tGroupID\tCtime\tDirName\n");
		while(dir = readdir(dp)){
			stat(dir->d_name,&filestat);
			printf("%ld\t%o\t%d\t%d\t%s\t%s\n",filestat.st_ino,filestat.st_mode,filestat.st_uid,filestat.st_gid,ctime(&filestat.st_atime),dir->d_name);
		}
	}
	else{
		printf("Error\n");
	}
}
