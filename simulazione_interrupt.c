#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void int1(){printf("interrupt 1\n");}
void int2(){printf("interrupt 2\n");}
void int3(){printf("interrupt 3\n");}


void main(){
	srand(time(NULL));
	void (*interrupts[])() = {int1, int2, int3};
	int scelta = 0;
	while(1){
		scelta = (rand() % 3);
		interrupts[scelta]();
		sleep(5);
	}
}
