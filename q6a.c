#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

static void cha(char *);

int main(){
	pid_t pid;
	if((pid = fork()) < 0)
		printf("Eror\n");
	else if(pid == 0)
		cha("ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp\n");
	else
		cha("ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n");
	exit(0);
}
void cha(char *str){
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;c=*ptr;ptr++)
		putc(c,stdout);
}
