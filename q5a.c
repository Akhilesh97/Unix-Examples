#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void f1(int, int, int, int);
static void f2(void);
static int globval;
static jmp_buf jmpbuf;
int main(){
	globval = 1;
	int autoval = 2;
	register int regival = 3;
	volatile int volaval = 4;
	static int statval = 5;
		
	if(setjmp(jmpbuf)!=0){
		printf("After long jump\n");
		printf("Global:%d\bAuto:%d\bRegi:%d\bVol:%d\bStat:%d\b\n",globval,autoval,regival,volaval,statval);
		exit(0);
	}
	globval = 93;
	autoval = 94;
	regival = 95;
	volaval = 96;
	statval = 97;
	f1(autoval,regival,volaval,statval);
	exit(0);
}
void f1(int autoval, int regival, int volaval, int statval){
	printf("Inside f1\n");
	printf("Global:%d\bAuto:%d\bRegi:%d\bVol:%d\bStat:%d\b\n",globval,autoval,regival,volaval,statval);
	globval = 1000;
	f2();
}
void f2(){
	longjmp(jmpbuf,1);
}

