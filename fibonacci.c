#include <stdio.h>
//a[i] = a[i-1] + a[i-2], a[0] = 0, a[1] = 1
#define TARGET 10

int fibonacci(int target);

void main(){
	int a = 0;
	int b = 1;
	int tmp = 0;
	for (int i = 2; i <= TARGET; i++){
		tmp = a + b;
		a = b;
		b = tmp;
	}
	printf("Fibonacci iter: %d\n",b);	
 	printf("Fibonacci rec: %d\n", fibonacci(TARGET));
}

int fibonacci(int target){
	if (target == 0) return 0;
	if (target == 1) return 1;

	return fibonacci(target-1) + fibonacci(target-2);

}
