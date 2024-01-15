#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
int rand_part(int a[], int p, int r);
int part(int a[], int p, int r);
void randomizedQuickSort(int a[], int p, int r);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int rand_part(int a[], int p, int r)
{
    int i = (rand() % (r - p + 1)) + p;
    int temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return part(a, p, r);
}
int part(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}
void randomizedQuickSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = rand_part(a, p, r);
        randomizedQuickSort(a, p, q - 1);
        randomizedQuickSort(a, q + 1, r);
    }
}
int main()
{
    int n;
    printf("Enter the size of the list(array): ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    srand(time(NULL)); // Seed the random number generator
    int p = 0;
    int r = n - 1;
    randomizedQuickSort(a, p, r);
    printf("\nAfter sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}
