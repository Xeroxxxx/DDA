#include <stdio.h>
#include <stdlib.h>
struct Job {
    char id;
    int deadline;
    int profit;
};
int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}
int findMaxDeadline(struct Job arr[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
    }
    return maxDeadline;
}
void jobSequencing(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compareJobs);
    int maxDeadline = findMaxDeadline(arr, n);
    char result[maxDeadline];
    int totalProfit = 0;
    int jobCount = 0;
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = '-';
    }
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (result[j] == '-') {
                result[j] = arr[i].id;
                totalProfit += arr[i].profit;
                jobCount++;
                break;
            }
        }
    }
    printf("Selected Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != '-') {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}
int main() {
    struct Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                         {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);
    jobSequencing(arr, n);
    return 0;
}
