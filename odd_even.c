//
// Created by Antonio on 06/03/2025.
//
#include <stdio.h>


int even_odd(int n);

int main(){
  printf("Insert a number: ");
  int n = 0;
  scanf("%d", &n);
  int res = even_odd(n);
  if(res) printf("%d is even\n", n);
  else printf("%d is odd\n", n);
  return 0;
}


int even_odd(int n){
  if (n % 2 == 0){
    return 1;
  }
  else{ return 0;}
}