#include <stdio.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void HeapSort(int A[], int n);
void BuildHeap(int A[], int n);
void Heapify(int A[], int i, int n);

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
    HeapSort(A, n - 1);
    printf("\nAfter sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", A[i]);
    }
    return 0;
}
void HeapSort(int A[], int n) {
    BuildHeap(A, n);
    for (int i = n; i >= 1; i--) {
        swap(&A[0], &A[i]);
        n = n - 1;
        Heapify(A, 0, n);
    }
}
void BuildHeap(int A[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        Heapify(A, i, n);
    }
}
void Heapify(int A[], int i, int n) {
    int l = 2 * i + 1; // left child of i
    int r = 2 * i + 2; // right child of i
    int largest = i;
    if (l <= n && A[l] > A[largest])
        largest = l;
    if (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        swap(&A[i], &A[largest]);
        Heapify(A, largest, n);
    }
}
