#include <stdio.h>

int fib(int n);

int main() {

    printf("FIBONACCI NUMBER!\n");
    printf("%d: %d\n", 4, fib(4));
    printf("%d: %d\n", 0, fib(0));
    printf("%d: %d\n", 10, fib(10));
}

int fib(int n) {
    if(n == 0)
        return 0;
    if(n < 2)
        return 1;
    return fib(n-1) + fib(n-2);
}
