#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

void deamonize()
{
pid_t pid=fork();

if(pid<0)
fprintf(stderr,"ErrorForking\n");
else if(pid)
{
printf("PIDofChild%d\n",pid);
exit(0);//killtheparentprocess,childisorphandedandrunsinthe

}

umask(0);
if(chdir("/")<0)
printf("Errorchangingdirectory\n");
if(setsid()<0)//makethechildprocessthesessionleader
printf("Errorcreatingsession\n");

printf("DemonCreated!\n");

}
int main()
{
deamonize();
//system("ps -axj");
return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	pid_t pid;
	if((pid = fork())<0)
		printf("Fork error\n");
	else if(pid > 0){
		printf("Inside parent\nChild id : %d\nParent id:%d\nParent killed\n",pid,getppid());
		exit(0);
	}
	else{
		printf("Inside child\nChild id:%d\nParent id:%d",pid,getppid());	
		if(setsid()<0){
			printf("Error creating seesion\n");
		}
	}
	system("ps -axj");
}*/
