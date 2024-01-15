#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    int weight;
    int value;
};

void knapsackBacktrack(int capacity, int currentIndex, int currentWeight, int currentValue, int n, struct Item items[], int *maxValue, int selectedItems[]) {
    if (currentIndex == n || currentWeight == capacity) {
        if (currentValue > *maxValue) {
            *maxValue = currentValue;

            for (int i = 0; i < n; ++i) {
                selectedItems[i] = 0;
            }

            for (int i = 0; i < currentIndex; ++i) {
                selectedItems[i] = 1;
            }
        }
        return;
    }

    if (currentWeight + items[currentIndex].weight <= capacity) {
        knapsackBacktrack(capacity, currentIndex + 1, currentWeight + items[currentIndex].weight, currentValue + items[currentIndex].value, n, items, maxValue, selectedItems);
    }

    knapsackBacktrack(capacity, currentIndex + 1, currentWeight, currentValue, n, items, maxValue, selectedItems);
}

int main() {
    struct Item items[] = {
        {2, 10},
        {3, 15},
        {5, 7},
        {7, 8},
        {1, 4}
    };

    int n = sizeof(items) / sizeof(items[0]);

    int capacity = 10;
    int maxValue = 0;
    int selectedItems[MAX_ITEMS] = {0};

    knapsackBacktrack(capacity, 0, 0, 0, n, items, &maxValue, selectedItems);

    for (int i = 0; i < n; ++i) {
        if (selectedItems[i]) {
            printf("Item %d\n", i + 1);
        }
    }

    printf("Maximum value: %d\n", maxValue);
    printf("\nName: Suprem bhatta");

    return 0;
}
