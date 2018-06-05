#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int source,dest,n,filesize,i;
	char *buf;
	if(argc != 3)
		printf("Error\n");
	else{
		if((source = open(argv[1],O_RDONLY)) < 0)
			printf("Error\n");
		if((dest = open(argv[2], O_WRONLY|O_TRUNC)) < 0)
			printf("Error\n");
		filesize = lseek(source, (off_t)0, SEEK_END);
		for(i = filesize - 1; i >= 0; i--){
			if(lseek(source,(off_t)i,SEEK_SET) < 0)	
				printf("Error");
			if((n = read(source, &buf, 1))!=1)
				printf("Error\n");
			if((n = write(dest,&buf, 1))!=1)
				printf("Error\n");
		}
	}
	printf("Done copying");
	close(source);
	close(dest);
}
