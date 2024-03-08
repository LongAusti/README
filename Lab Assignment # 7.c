#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps[arr[min_idx]]++;
        swaps[arr[i]]++;
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[101] = {0}; // Array to store number of swaps for each value in array1
    int swaps2[101] = {0}; // Array to store number of swaps for each value in array2

    bubbleSort(array1, n1, swaps1);
    selectionSort(array2, n2, swaps2);

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d times %d is swapped\n", array1[i], swaps1[array1[i]], array1[i]);
    }
    int total_swaps1 = 0;
    for (int i = 0; i < 101; i++) {
        total_swaps1 += swaps1[i];
    }
    printf("Total # of swaps: %d\n\n", total_swaps1);

    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d times %d is swapped\n", array2[i], swaps2[array2[i]], array2[i]);
    }
    int total_swaps2 = 0;
    for (int i = 0; i < 101; i++) {
        total_swaps2 += swaps2[i];
    }
    printf("Total # of swaps: %d\n", total_swaps2);

    return 0;
}
