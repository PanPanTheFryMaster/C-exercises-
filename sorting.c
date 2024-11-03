#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visualizza_array(int *array, int size);
void ordina_array(int *array, int size);

void main(){
	srand(time(NULL));
	int array[20];
	int size = sizeof(array)/sizeof(array[0]);
	for (int i = 0; i < 20; i++){
		array[i] = rand() % 21;
	}
	visualizza_array(array, size);
	
	ordina_array(array, size);
	printf("Visualizzazione dopo ordinamento: ");
	ordina_array(array, size);
	visualizza_array(array, size);
}


void visualizza_array(int *array, int size){
	for (int i = 0; i < size; i++){
		printf(" %d ", array[i]);
	}
	printf("\n");
}


void ordina_array(int *array, int size){
	int tmp = 0;
	for (int i = 0; i < size-1; i++){
		for (int j = 0; j < size -i-1; j++){
			if (array[j] > array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}

	}

}
