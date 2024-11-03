#include <stdio.h>
#include <stdlib.h>



int calcola(int a, int b, int (*operazione)(int a, int b));
int somma(int a, int b){ return a+b;}
int sottrazione(int a, int b){ return a-b;}
int divisione(int a, int b){
	if (b == 0) return 0;
	return a/b;
}
int moltiplicazione(int a, int b){ return a*b;}

void main(){
	int a = 0, b = 0;
	char operation;
	int res = 0;
	while(1){
		printf("Inserisci a: ");
		scanf("%d", &a);
		printf("Inserisci b: ");
		scanf("%d", &b);
		printf("Scegli operazione +, -, /, *: ");
		scanf(" %c", &operation);
		switch(operation){
			case '+':
				res = calcola(a,b,somma);
				break;
			case '-':
				res = calcola(a,b,sottrazione);
				break;
			case '/':
				res = calcola(a,b, divisione);
				break;
			case '*':
				res = calcola(a, b, moltiplicazione);
				break;
			default:
				break;
		}
		printf("Res: %d\n", res);

	}


}


int calcola(int a, int b, int (*operazione)(int a, int b)){
	return operazione(a,b);
}
