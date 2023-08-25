#include <stdio.h>
void mergeLst(int lst1[], int m, int lst2[], int n, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (lst1[i] < lst2[j]) {
            result[k++] = lst1[i++];
        } else {
            result[k++] = lst2[j++];
        }
    }
    
    while (i < m) {
        result[k++] = lst1[i++];
    }
    
    while (j < n) {
        result[k++] = lst2[j++];
    }
}

int main() {
    int lst1[] = {1, 3, 5, 7};
    int m = sizeof(lst1) / sizeof(lst1[0]);
    
    int lst2[] = {2, 4, 6, 8};
    int n = sizeof(lst2) / sizeof(lst2[0]);
    
    int merged[m + n];
    mergeLst(lst1, m, lst2, n, merged);
    
    printf("Merged lst: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
