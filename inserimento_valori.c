#include <stdio.h>

void main(){
	int num = 0;
	printf("Inserire un intero: \n");
	scanf("%d", &num);
	printf("Intero inserito: %d, Occupazione in memoria: %zu, Indirizzo: %p \n", num, sizeof(num), (void*)&num);
	char ch;
	printf("Inserire un carattere: \n");
	scanf(" %c", &ch);
	printf("Char inserito: %c, Occupazione in memoria: %zu, Indirizzo: %p  \n", ch, sizeof(ch), (void*)&ch);
	float fl;
	printf("Inserire float: \n");
	scanf("%f", &fl);
	printf("Float inserito: %.2f, Occupazione in memoria: %zu, Indirizzo: %p \n",fl, sizeof(fl), (void*)&fl);
	double db;
	printf("inserire double: \n");
	scanf("%lf", &db);
	printf("Double inserito: %lf, Occupazione in memoria: %zu, Indirizzo: %p \n", db, sizeof(db), (void*)&db); 
}
