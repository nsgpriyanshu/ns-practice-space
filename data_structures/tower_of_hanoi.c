#include <stdio.h>

void toh(int n, char beg, char end, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", beg, end);
        return;
    }
    toh(n - 1, beg, aux, end);
    printf("Move disk %d from %c to %c\n", n, beg, end);
    toh(n - 1, aux, end, beg);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\nSolution for Tower of Hanoi with %d disks:\n", n);
    toh(n, 'A', 'C', 'B');
    return 0;
}
