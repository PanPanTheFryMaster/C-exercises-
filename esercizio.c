#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void visualizza_array(int *array, int size);
int trova_max(int *array, int size);
int trova_min(int *array, int size);
void ordina_arr(int *array, int size);
float calcola_media(int *array, int size);

void main(){
	srand(time(NULL));
	int array[20];
	int size = 20, max = 0, min = 0;
	float media = 0;
	for (int i=0; i < 20; i++){
		array[i] = rand() % 21;
	}
	puts("Array appena creato");
	visualizza_array(array, size);
	puts("Max: ");
	max = trova_max(array, size);
	printf("%d", max);
	puts("Min: ");
	min = trova_min(array, size);
	printf("%d", min);
	ordina_arr(array,size);
	puts("Array post ordinamento");
	visualizza_array(array, size);
	media = calcola_media(array, size);
	printf("Media: %f", media);

}

void visualizza_array(int *array, int size){
	for (int i = 0; i < size; i++){
		printf(" %d,", array[i]);
	}
}

int trova_max(int *array, int size){
	int max = 0;
	for (int i=0; i < size; i++){
		max = array[i] > max ? array[i] : max;
	}
	return max;
}

int trova_min(int *array, int size){
	int min = 99999;
	for (int i=0; i < size; i++){
		min = array[i] < min ? array[i]: min;
	}
	return min;
}

void ordina_arr(int *array, int size){
	int tmp = 0;
	for (int i =0 ; i < size - 1; i++){
		for (int j =0; j < size - i -1; j++){
			if (array[j] > array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}

}


float calcola_media(int *array, int size){
	float sum = 0;
	for (int i =0 ; i < size; i++){
		sum += array[i];
	}
	return sum/size;
}
