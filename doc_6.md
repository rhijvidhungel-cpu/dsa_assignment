# Binary Heap Implementation: Min-Heap and Max-Heap

This program demonstrates how to transform an unsorted array into both a **Min-Heap** and a **Max-Heap** using the heapify process.

---

## (a) Data Structure Definition

While heaps are logically represented as **Complete Binary Trees**, they are physically implemented using a **linear array** for space efficiency.  

- **Root Element**: Always stored at index `0`.  
- **Parent-Child Mapping**: For any element at index `i`:  
  - Left Child: `2*i + 1`  
  - Right Child: `2*i + 2`  
  - Parent: `floor((i-1)/2)`  

The array representation ensures that heap operations can be performed efficiently without the need for explicit tree nodes.

---

## (b) Function Descriptions

### 1. `adjustMinHeap(int heap[], int length, int idx)`  
- **Purpose**: Recursively ensures that a subtree rooted at index `idx` satisfies the **Min-Heap property**.  
- **Logic**: Compares the parent node with its children. If a child is smaller, it swaps with the parent and continues heapifying down the tree.

### 2. `buildMinHeap(int heapArr[], int length)`  
- **Purpose**: Converts an arbitrary array into a **Min-Heap**.  
- **Algorithm**: Starts from the last non-leaf node (`length/2 - 1`) and calls `adjustMinHeap()` on each node moving backwards to the root.

### 3. `adjustMaxHeap(int heap[], int length, int idx)`  
- **Purpose**: Recursively ensures that a subtree rooted at index `idx` satisfies the **Max-Heap property**.  
- **Logic**: Compares the parent node with its children. If a child is larger, it swaps with the parent and continues heapifying down the tree.

### 4. `buildMaxHeap(int heapArr[], int length)`  
- **Purpose**: Converts an arbitrary array into a **Max-Heap**.  
- **Algorithm**: Starts from the last non-leaf node and calls `adjustMaxHeap()` on each node moving backwards to the root.

### 5. `printArray(int arr[], int length)`  
- **Purpose**: Displays the elements of an array in sequence, representing the heap in **level-order traversal**.

---

## (c) Main Method Organization

The `main()` function follows a structured workflow:

1. **Input Collection**: Prompts the user for the number of elements and the elements themselves.  
2. **Array Duplication**: Copies the original array into `maxHeapArr` to demonstrate both Min-Heap and Max-Heap from the same data.  
3. **Heap Construction**:  
   - Calls `buildMinHeap(numbers, count)` to construct the Min-Heap.  
   - Calls `buildMaxHeap(maxHeapArr, count)` to construct the Max-Heap.  
4. **Display**: Prints the resulting Min-Heap and Max-Heap arrays to show their level-order representation.

---

## (d) Sample Output
Enter elements:
6 5 3 4 9 0 
Min Heap:
0 4 3 5 9 6
Max Heap:
9 6 3 4 5 0
