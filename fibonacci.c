// fib[0] = 0, fib[1] = 1, fib[i] = fib[i-2] + fib[i-1]
#include <stdio.h>

int fibonacci(int target);

void main(){
	int num = fibonacci(7);
	printf("res recursive: %d\n", num);

	int temp = 0;
	int a = 0;
	int b = 1;
	for (int i = 1; i < 7; i++){
		temp = b;
		b = a + b;
		a = temp;
	}
	printf("res iterativo: %d\n", b);
}


int fibonacci(int target){
	if (target == 0)
		return 0;
	if (target == 1)
		return 1;

	return fibonacci(target-1) + fibonacci(target-2);
}
