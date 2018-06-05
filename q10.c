#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void callback(){
	printf("Interrupt received\n");
	(void)signal(SIGINT,SIG_DFL);
}

int main(){
	int ch;	int i = 0;
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			(void)signal(SIGINT,callback);
			break;
		case 2:
			(void)signal(SIGINT,SIG_IGN);
			break;
		
	}
	while(1){
		printf("Press ctrl+c\n");
		sleep(1);
		i++;
		if(i == 10 && ch == 2)
			(void)signal(SIGINT,SIG_DFL);
	}
}
