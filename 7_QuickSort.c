#include <stdio.h>
void QuickSort(int A[], int l, int h);
int Partition(int A[], int l, int h);
int main() {
    int n;
    printf("Enter the size of the list(array): ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Before sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", A[i]);
    }
    int l = 0;
    int h = n - 1; // Adjusted the upper bound to be n-1
    QuickSort(A, l, h);

    printf("\nAfter sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", A[i]);
    }
    return 0;
}
void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
int Partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;
    while (i < j) {
        do {
            i++;
        } while (A[i] <= pivot);
        do {
            j--;
        } while (A[j] > pivot);
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[l];
    A[l] = A[j];
    A[j] = temp;

    return j;
}
