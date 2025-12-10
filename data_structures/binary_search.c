#include <stdio.h>
#include <conio.h>

void main() {
    int n, beg = 0, end, mid, arr[50], key, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    end = n - 1;

    printf("Enter the elements of array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements with their memory locations:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d present at location %u\n", i, arr[i], &arr[i]);
    }

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    mid = (beg + end) / 2;
    while (beg <= end) {
        if (arr[mid] == key) {
            printf("\nElement %d found at index: %d\n", key, mid);
            printf("Element address: %u\n", &arr[mid]);
            break;
        } else if (key > arr[mid]) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (beg + end) / 2;
    }

    if (beg > end) {
        printf("\nKey not found\n");
    }
}
