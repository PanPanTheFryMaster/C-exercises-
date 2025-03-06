#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int size);

int main(){
  int array[10];
  srand(time(NULL));
  for (int i = 0; i < 10; i++){
    array[i] = rand() % 101;
  }
  for (int i = 0; i < 10; i++){
    printf("%d ", array[i]);
  }
  printf("\n\n");
  bubble_sort(array, 10);

  for (int i = 0; i < 10; i++){
    printf("%d ", array[i]);
  }
}

void bubble_sort(int *arr, int size){
  for (int i = 0; i < size - 1; i++){
    for (int j =0; j < size - i - 1; j++){
      if (arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}