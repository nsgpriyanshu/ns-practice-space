#include <stdio.h>
#include <conio.h>

void main() {
    int n, i, j, min, temp, arr[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements with memory locations (Before Sorting):\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, arr[i], &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nArray elements with memory locations (After Sorting):\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, arr[i], &arr[i]);
    }

}
