#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a number.\n");
        return 1;
    }
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fib[i];
    }

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d", fib[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("Sum of Fibonacci Series: %d\n", sum);

    return 0;
}
