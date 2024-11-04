#include <stdio.h>
#include <stdlib.h>
#define TARGET 5


int fibonacci(int target);

void main(){
	int a = 0;
	int b = 1;
	int tmp = 0;
	for (int i = 2; i <= TARGET; i++){
		tmp = b;
		b = b + a;
		a = tmp;
	}

	printf("Fib iterative: %d\n", b);
	
	b = fibonacci(TARGET);
	printf("Fib recursive: %d\n", b);
}

int fibonacci(int target){
	if (target == 0) return 0;
	if (target == 1) return 1;
	return fibonacci(target-1) + fibonacci(target-2);
}
