#include <stdio.h>

void swap_inplace(int *a,int *b);

void main(){
	int a = 1, b = 0;
	swap_inplace(&a,&b);
	printf("A: %d, B: %d \n", a,b);

}

void swap_inplace(int *a, int *b){
	int tmp; 
	tmp = *a;
	*a = *b;
	*b = tmp;
}
