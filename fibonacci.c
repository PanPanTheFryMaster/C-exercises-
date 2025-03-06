#include <stdio.h>

int fibonacci_rec(int target);

int main() {
    int a = 0;
    int b = 1;
    int fib = 0;
    int target = 0;
    printf("Enter target: ");
    scanf("%d", &target);


    for (int i = 1; i < target; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    printf("The iterative fibonacci number of index %d is: %d\n",target, fib);

    fib = fibonacci_rec(target);
    printf("The recursive fibonacci number of index %d is: %d\n",target, fib);
    return 0;
}

int fibonacci_rec(int target) {

    if(target == 0) {return 0;}
    if (target == 1) {return 1;}
    return fibonacci_rec(target-1) + fibonacci_rec(target-2);
}