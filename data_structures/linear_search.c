#include <stdio.h>
#include <conio.h>

void main() {
    int n, f = 0, a[50], i, key;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nArray elements with their memory locations:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, a[i], &a[i]);
    }

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("\nElement %d found at index: %d\n", key, i);
            printf("Element address: %u\n", &a[i]);
            f = 1;
            break;
        }
    }

    if (f == 0) {
        printf("\nElement not found!\n");
    }

}
