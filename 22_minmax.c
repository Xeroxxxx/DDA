#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result;

    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    } else if (high == low + 1) {
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        return result;
    } else {
        int mid = (low + high) / 2;
        MinMax left = findMinMax(arr, low, mid);
        MinMax right = findMinMax(arr, mid + 1, high);

        result.min = (left.min < right.min) ? left.min : right.min;
        result.max = (left.max > right.max) ? left.max : right.max;

        return result;
    }
}

int main() {
    // User input for array size and elements
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the minimum and maximum using Divide and Conquer
    MinMax result = findMinMax(arr, 0, n - 1);

    // Print the result
    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    // Add your name
    printf("\nSupreme Bhatta\n");

    return 0;
}
