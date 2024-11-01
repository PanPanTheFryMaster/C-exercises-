#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cod;
	int pagine;
	float costo;
}book;


void main(){
	book *array = NULL;
	int cnt = 0;
	int flag = 0;
	while (flag == 0){
		cnt++;
		array = (book *) realloc(array, sizeof(book) * cnt);
		printf("Inserire codice: ");
        	scanf("%d", &array[cnt - 1].cod);
        	printf("Inserire pagine: ");
        	scanf("%d", &array[cnt - 1].pagine);
        	printf("Inserire costo: ");
        	scanf("%f", &array[cnt - 1].costo);
		printf("Inserire ancora? 0/1");
		scanf("%d", &flag);
	}
	for (int i=0; i < cnt; i++){
		printf("Codice: %d, Pagine: %d, Costo: %f", array[i].cod, array[i].pagine, array[i].costo);
	}
	printf("\n");
	free(array);
}
