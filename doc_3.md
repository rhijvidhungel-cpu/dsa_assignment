# Checking balance number of parenthesis

## Objective:
The objective of this program is to implement a function to traverse a linked list in reverse order without modifying the original list.

### Defining Data-Structures:
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

**Explanation:**
* Node is a structure representing a linked list node.

* data stores the value of the node.

* next points to the next node in the list.

* head points to the first node of the linked list.

**Functions:**
* createNode(int value): Creates and returns a new node with the given value.

* insertEnd(Node** head, int value): Inserts a node at the end of the linked list.

* reverseTraversal(Node* head): Recursively traverses the linked list in reverse order and prints node values.

* displayList(Node* head): Displays the linked list in normal order.

* main(): The main function performs the following operations:<br>

* Creates an empty linked list.<br>

* Inserts sample nodes into the list.<br>

* Displays the linked list in normal order.<br>

* Calls reverseTraversal() to display the list in reverse.<br>

**Sample Output:**
Original Linked List: 10 -> 20 -> 30 -> 40 -> NULL
Reverse Traversal: 40 30 20 10 
