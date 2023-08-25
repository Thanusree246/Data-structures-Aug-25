#include <stdio.h>
int main() {
    int arr[] = {2, 7, 15, 10, 8, 23, 14, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Even numbers: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Odd numbers: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
