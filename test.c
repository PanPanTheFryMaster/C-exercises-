#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Ordina array
void bubble_sort(int *array, int size);
int main() {
    int *array = NULL;
    int size = 0;
    printf("Enter size of array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }

    printf("Array before sorting:\n");
    for (int i = 0; i < size; i++) {printf("%d ", array[i]);}
    bubble_sort(array, size);
    printf("\nArray after sorting:\n");
    for (int i = 0; i < size; i++) {printf("%d ", array[i]);}



    //apply fibonacci to a given sequence
    int target = INT_MAX;
    int fib = array[0] + array[1];
    printf("Enter a target: ");
    scanf("%d", &target);
    while (target > size) {
        printf("Enter a valid target: ");
        scanf("%d", &target);
    }
    for (int i=2 ; i < target; i++) {
        fib += array[i];
    }

    return 0;
}


void bubble_sort(int *array, int size) {
    int tmp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}