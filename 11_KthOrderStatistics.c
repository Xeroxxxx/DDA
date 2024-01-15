#include<stdio.h>
#include<conio.h>
int quickSort(int a[], int p, int r, int k);
int part(int a[], int p, int r);
int main() {
    int i, n;
    printf("Enter the size of the list (array): ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements for the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("ARRAY: \n");
    for (i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    int k;
    printf("\nEnter the Kth order: ");
    scanf("%d", &k);
    int KthSmallestElement = quickSort(a, 0, n - 1, k);
    printf("\n%dth smallest element is: %d", k, KthSmallestElement);
    return 0;
}
int quickSort(int a[], int p, int r, int k) {
    if (p < r) {
        int q = part(a, p, r);
        if (q == k - 1)
            return a[q];
        else if (q > k - 1)
            return quickSort(a, p, q - 1, k);
        else
            return quickSort(a, q + 1, r, k);
    }
    return a[p]; // Added to return the pivot element when p == r
}
int part(int a[], int p, int r) {
    int pivot = p;
    int i = p, j = r;
    while (i < j) {
        while (a[i] < a[pivot] && i < r)
            i++;
        while (a[j] > a[pivot] && j >= p)
            j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;
    return j;
}
