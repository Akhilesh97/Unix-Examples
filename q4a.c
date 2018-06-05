#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<utime.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	struct stat statbuf1;
	struct stat statbuf2;
	struct utimbuf times;
	if((stat(argv[1],&statbuf1)) < 0)		
		printf("Error");
	if((stat(argv[2],&statbuf2)) < 0)
		printf("Error");
	printf("Before copying\n");
	printf("Access Time\tModification time\n");
	printf("%s\t%s\n",ctime(&statbuf1.st_atime),ctime(&statbuf1.st_mtime));
	
	times.modtime = statbuf2.st_mtime;
	times.actime = statbuf2.st_atime;
	
	if((utime(argv[1],&times))<0)
		printf("Error");
	if((stat(argv[1],&statbuf1)) < 0)
                printf("Error");
        printf("After copying\n");
        printf("Access Time\tModification time\n");
        printf("%s\t%s\n",ctime(&statbuf1.st_atime),ctime(&statbuf1.st_mtime));
}
