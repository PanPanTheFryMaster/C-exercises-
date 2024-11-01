#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void bubble_sort(int *array);

void main(){
	srand(time(NULL));
	int array[20];
	int size = sizeof(array)/sizeof(int);
	for (int i = 0; i < size; i++){
		array[i] = rand() % 21;
	}

	for (int i = 0; i < size; i++){
		printf ("%d, ", array[i]);
	}
	printf("\n");

	bubble_sort(array);
	printf("Array dopo bubble sort\n");
	for (int i = 0; i < size; i++){
                printf ("%d, ", array[i]);
        }

}


void bubble_sort(int *array){
	int tmp;
	int size = 20;
	for (int i = 0; i < size -1; i++){
		for (int j =0 ; j < size - i - 1; j++){
			if (array[j] > array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
}

