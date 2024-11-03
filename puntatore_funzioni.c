#include <stdio.h>

int somma(int a, int b){
	return a+b;
}
int sottrazione(int a, int b){ 
	return a-b;
}
int calcola(int a, int b, int (*operazione)(int a, int b)){
	return operazione(a,b);
}
void main(){
	int a = 0, b = 0;
	printf("Definisci a: ");
	scanf("%d", &a);
	printf("Definisci b: ");
	scanf("%d", &b);
	printf("Somma: %d\n", calcola(a, b, somma));
	printf("Sottrazione: %d\n", calcola(a, b, sottrazione));


}
