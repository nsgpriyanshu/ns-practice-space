#include <stdio.h>
#include <conio.h>

void main() {
    int n, c, d, swap, arr[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (c = 0; c < n; c++) {
        printf("A[%d]: ", c);
        scanf("%d", &arr[c]);
    }

    printf("\nArray elements with memory locations (Before Sorting):\n");
    for (c = 0; c < n; c++) {
        printf("A[%d] = %d present at location %u\n", c, arr[c], &arr[c]);
    }

    for (c = 0; c < n - 1; c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (arr[d] > arr[d + 1]) {
                swap = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = swap;
            }
        }
    }

    printf("\nArray elements with memory locations (After Sorting):\n");
    for (c = 0; c < n; c++) {
        printf("A[%d] = %d present at location %u\n", c, arr[c], &arr[c]);
    }

}
