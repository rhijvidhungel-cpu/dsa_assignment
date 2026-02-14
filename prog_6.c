#include <stdio.h>
#define MAX_SIZE 100


void adjustMinHeap(int heap[], int length, int idx) {
    int smallestIdx = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < length && heap[leftChild] < heap[smallestIdx])
        smallestIdx = leftChild;
    if (rightChild < length && heap[rightChild] < heap[smallestIdx])
        smallestIdx = rightChild;

    if (smallestIdx != idx) {
        int temp = heap[idx];
        heap[idx] = heap[smallestIdx];
        heap[smallestIdx] = temp;
        adjustMinHeap(heap, length, smallestIdx);
    }
}

void buildMinHeap(int heapArr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        adjustMinHeap(heapArr, length, i);
    }
}


void adjustMaxHeap(int heap[], int length, int idx) {
    int largestIdx = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < length && heap[leftChild] > heap[largestIdx])
        largestIdx = leftChild;
    if (rightChild < length && heap[rightChild] > heap[largestIdx])
        largestIdx = rightChild;

    if (largestIdx != idx) {
        int temp = heap[idx];
        heap[idx] = heap[largestIdx];
        heap[largestIdx] = temp;
        adjustMaxHeap(heap, length, largestIdx);
    }
}

void buildMaxHeap(int heapArr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        adjustMaxHeap(heapArr, length, i);
    }
}


void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int numbers[MAX_SIZE], count;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    printf("Enter elements:\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

   
    int maxHeapArr[MAX_SIZE];
    for (int i = 0; i < count; i++) {
        maxHeapArr[i] = numbers[i];
    }

    
    buildMinHeap(numbers, count);
    printf("\nMin Heap:\n");
    printArray(numbers, count);

    
    buildMaxHeap(maxHeapArr, count);
    printf("\nMax Heap:\n");
    printArray(maxHeapArr, count);

    return 0;
}
