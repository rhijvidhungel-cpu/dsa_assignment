# Sorting Algorithm Performance Comparison

This program generates a list of random integers and allows the user to compare the performance of four different sorting algorithms by tracking their comparison and swap counts.

---

## (a) Data Structure Definition

The program primarily uses a **Dynamic Array** (Variable Length Array in C) to store the integers.

* **`numbers[n]`**: A standard integer array where `n` is defined by the user at runtime.
* **Global Counters**: 
    * `compCount`: Tracks how many times two elements are compared.
    * `swapCount`: Tracks how many times elements are moved or exchanged in memory.

---

## (b) Function Descriptions

The program implements four distinct sorting strategies:

| Algorithm | Type | Description |
| :--- | :--- | :--- |
| **Bubble Sort** | Exchange | Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. |
| **Selection Sort** | Selection | Divides the array into a sorted and unsorted part; it repeatedly finds the minimum element from the unsorted part and moves it to the beginning. |
| **Insertion Sort** | Insertion | Builds the final sorted array one item at a time by inserting an element into its correct position among previously sorted elements. |
| **Merge Sort** | Divide & Conquer | Recursively splits the array into halves, sorts them, and then merges them back together in order. |

### Additional Functions

* **`swapElements(int *x, int *y)`**: Swaps the values of two integer variables.
* **`printArray(int arr[], int len)`**: Prints the elements of the array in a single line.
* **`generateRandomArray(int arr[], int len)`**: Populates the array with random integers between 1 and 500.
* **`mergeArray(int arr[], int left, int mid, int right)`**: Helper function for Merge Sort to merge two sorted subarrays.
* **`mergeSort(int arr[], int left, int right)`**: Implements the recursive Merge Sort algorithm.

---

## (c) Main Method Organization

The `main()` function follows a structured flow:

1. **Array Generation**: Prompts the user for the number of elements and fills the array with random integers.
2. **Menu Display**: Shows the sorting algorithm options and reads the user’s choice.
3. **Execution**: Calls the selected sorting function using a `switch` statement.
4. **Analytics and Display**:
    - Shows the array **before** sorting.
    - Performs the sorting while tracking comparisons and swaps.
    - Shows the array **after** sorting.
    - Prints the total number of comparisons and swaps (swaps not counted for Merge Sort).

---

## (d) Sample Output

```text
Enter number of elements: 5
Random Array:
42 468 335 1 170

Choose Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Before Sorting:
42 468 335 1 170

After Sorting:
1 42 170 335 468

Total Comparisons: 10
Total Swaps: 6
