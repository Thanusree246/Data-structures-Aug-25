#include <stdio.h>
#include <string.h>

int searchRegistrationNumber(char regNumbers[][20], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(regNumbers[i], target) == 0) {
            return i; 
        }
    }
    
    return -1; 
}

int main() {
    char regNumbers[][20] = {"192224190", "192224191", "192224193", "192224193", "192224194"};
    int size = sizeof(regNumbers) / sizeof(regNumbers[0]);
    
    char target[20];
    printf("Enter the registration number to search: ");
    scanf("%s", target);
    
    int foundIndex = searchRegistrationNumber(regNumbers, size, target);
    if (foundIndex != -1) {
        printf("Registration number %s found at index %d.\n", target, foundIndex);
    } else {
        printf("Registration number %s not found.\n", target);
    }
    
    return 0;
}
