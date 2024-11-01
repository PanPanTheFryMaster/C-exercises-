#include <stdio.h>
#include <stdlib.h>
#define TARGET 9

int fibonacci(int num);

void main(){
	int res = 0;
	res = fibonacci(TARGET);
	printf("Risultato: %d\n", res);

	int array[10];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <= TARGET; i++){
		array[i] = array[i-1] + array[i-2];
	}
	for (int i = 0; i <= TARGET; i++){
		printf("%d: %d ",i, array[i]);
	}
	printf("\n");

}



int fibonacci(int num){
	if (num == 0) return 0;
	if (num == 1) return 1;
	return fibonacci(num-1) + fibonacci(num-2);
}
