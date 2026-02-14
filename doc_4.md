# Checking balance number of parenthesis

## Objective:
The objective of this program is to implement a doubly linked list using structures and demonstrate how to:
* Insert a node after a given node.
* Delete a specific node from the list.
* Traverse and display the list.

### Defining Data-Structures:
```c
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;
```

**Explanation:**
* Node structure has three fields:

 - value stores the data of the node.

 - next points to the next node in the list.

 - prev points to the previous node in the list.

* Each node is dynamically created using malloc.

* The prev and next pointers help in traversing forwards and backwards in the doubly linked list.

**Functions:**
* Node* createNode(int val): Creates and returns a new node with the given value.

* void insertAfterNode(Node* target, int val): Inserts a new node with the given value after the specified node.

* void deleteSpecificNode(Node** headRef, Node* delNode): Deletes the specified node from the list and updates the links.

* void displayList(Node* head): Traverses the list from head and prints all the node values in order.

* main(): Demonstrates the use of the above functions by:

 - Creating initial nodes and linking them.

 - Displaying the initial doubly linked list.

 - Inserting a node after a specified node.

 - Deleting a specific node.

 - Displaying the list after each operation.

**Sample Output:**
Initial Doubly Linked List:
5 <-> 10 <-> 15 <-> 20 -> NULL

After inserting 12 after 10:
5 <-> 10 <-> 12 <-> 15 <-> 20 -> NULL

After deleting node with value 15:
5 <-> 10 <-> 12 <-> 20 -> NULL
