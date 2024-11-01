#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>




int calcola_minimo(int *array, int size);
int calcola_massimo(int *array, int size);
double calcola_media(int *array, int size);
void ordina_array(int *array, int size);


void main(){
	int min = 0, max = 0;
	double media = 0;
	srand(time(NULL));
	int array[10];
	for (int i = 0; i < 10; i++){
		array[i] = rand() % 11;
	}
	for (int i = 0; i < 10; i++){
		printf("Array[%d] = %d; ", i, array[i]);
	}
	printf("\n");
	min = calcola_minimo(array, 10);
	max = calcola_massimo(array, 10);
	printf("Max: %d, Min: %d \n", max, min);
	media = calcola_media(array, 10);
	printf("Media: %lf \n", media);
	ordina_array(array, 10);
	for (int i = 0; i < 10; i++){
                printf("Array[%d] = %d; ", i, array[i]);
        }
	printf("\n");

}


int calcola_minimo(int *array, int size){
	int min = INT_MAX;
	for (int i = 0; i < size; i++){
		if (array[i] < min) min = array[i];
	}
	return min;
}


int calcola_massimo(int *array, int size){
	int max = INT_MIN;
	for (int i = 0; i < size; i++){
		if (array[i] > max) max = array[i];
	}
	return max;
}

double calcola_media(int *array, int size){
	double media = 0;
	for (int i = 0; i < size; i++){
		media += array[i];
	}
	return (media/size);

}

void ordina_array(int *array, int size){
	int temp = 0;
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-i-1; j++){
			if (array[j] > array[j + 1]){
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}
