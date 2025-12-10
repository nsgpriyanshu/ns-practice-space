#include <stdio.h>
#include <conio.h>

void main() {
    int n, i, j, key, arr[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements with memory locations (Before Sorting):\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, arr[i], &arr[i]);
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("\nArray elements with memory locations (After Sorting):\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, arr[i], &arr[i]);
    }

}
