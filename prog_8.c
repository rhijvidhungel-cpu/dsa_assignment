#include <stdio.h>
#include <stdlib.h>

long long compCount = 0, swapCount = 0;

void swapElements(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int data[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            compCount++;
            if (data[j] > data[j + 1]) {
                swapCount++;
                swapElements(&data[j], &data[j + 1]);
            }
        }
    }
}

void selectionSort(int data[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            compCount++;
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            swapCount++;
            swapElements(&data[i], &data[minIndex]);
        }
    }
}

void insertionSort(int data[], int len) {
    for (int i = 1; i < len; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0) {
            compCount++;
            if (data[j] > key) {
                swapCount++;
                data[j + 1] = data[j];
                j--;
            } else {
                break;
            }
        }
        data[j + 1] = key;
    }
}

void mergeArray(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        compCount++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArray(arr, left, mid, right);
    }
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generateRandomArray(int arr[], int len) {
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 500 + 1; // numbers 1 to 500
}

int main() {
    int n, algoChoice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    generateRandomArray(numbers, n);

    printf("Random Array:\n");
    printArray(numbers, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &algoChoice);

    printf("\nBefore Sorting:\n");
    printArray(numbers, n);

    compCount = swapCount = 0;

    switch (algoChoice) {
        case 1: bubbleSort(numbers, n); break;
        case 2: selectionSort(numbers, n); break;
        case 3: insertionSort(numbers, n); break;
        case 4: mergeSort(numbers, 0, n - 1); break;
        default: printf("Invalid choice!\n"); return 0;
    }

    printf("\nAfter Sorting:\n");
    printArray(numbers, n);

    printf("\nTotal Comparisons: %lld\n", compCount);
    if (algoChoice != 4)
        printf("Total Swaps: %lld\n", swapCount);
    else
        printf("Swaps: Not applicable for Merge Sort\n");

    return 0;
}
