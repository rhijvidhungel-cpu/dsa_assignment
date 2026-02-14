# Documentation: Heap Implementation in C

## (a) Explanation of Data Structures

In this program, the primary data structure used is an **array** to represent heaps:

- **Min Heap and Max Heap Arrays**:  
  Arrays store elements of the heap. The parent-child relationship is maintained using array indices:
  - For an element at index `i`:
    - **Left child** → `2*i + 1`
    - **Right child** → `2*i + 2`
  - **Min Heap property**: Parent ≤ Children  
  - **Max Heap property**: Parent ≥ Children

No additional structures like structs or linked nodes are used, keeping the implementation simple and array-based.

---

## (b) Description of Functions

### 1. `adjustMinHeap(int heap[], int length, int idx)`  
- **Purpose**: Adjusts a subtree rooted at index `idx` to satisfy the **min heap property**.  
- **Parameters**:  
  - `heap[]` → Array representing the heap  
  - `length` → Number of elements in the heap  
  - `idx` → Index of the subtree root to adjust  
- **Operation**:  
  1. Finds the smallest among parent and children  
  2. Swaps if parent is not smallest  
  3. Recursively adjusts affected subtree

### 2. `buildMinHeap(int heapArr[], int length)`  
- **Purpose**: Converts an unsorted array into a **min heap**.  
- **Operation**:  
  - Starts from last non-leaf node (`length/2 - 1`)  
  - Calls `adjustMinHeap()` for each non-leaf node in reverse level order

### 3. `adjustMaxHeap(int heap[], int length, int idx)`  
- **Purpose**: Adjusts a subtree rooted at index `idx` to satisfy the **max heap property**.  
- **Operation**:  
  - Similar to `adjustMinHeap`, but ensures parent ≥ children

### 4. `buildMaxHeap(int heapArr[], int length)`  
- **Purpose**: Converts an unsorted array into a **max heap**.  
- **Operation**:  
  - Uses `adjustMaxHeap()` on all non-leaf nodes in reverse order

### 5. `printArray(int arr[], int length)`  
- **Purpose**: Prints the elements of an array in sequence  
- **Parameters**:  
  - `arr[]` → Array to print  
  - `length` → Number of elements

---

## (c) Overview of `main()` Method

The `main()` function performs the following tasks:

1. Reads **number of elements** and the **elements themselves** from the user.  
2. Stores elements in an array `numbers[]`.  
3. Copies the array into `maxHeapArr[]` to preserve original data for max heap.  
4. Calls `buildMinHeap(numbers, count)` to construct a min heap.  
5. Displays the min heap using `printArray()`.  
6. Calls `buildMaxHeap(maxHeapArr, count)` to construct a max heap.  
7. Displays the max heap using `printArray()`.  

The program ends after displaying both heaps.

---

## (d) Sample Output

