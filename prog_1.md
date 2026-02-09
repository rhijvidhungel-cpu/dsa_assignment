# Checking balance number of parenthesis

## Objective:
The objective of this program is to analyze a mathematical expression and check
if it has a balanced number of parentheses `'()','{}','[]'`.

### Defining Data-Structures:
```c
#define size 50
char STK[size];
int top = -1;

**Explanation:**
* #define size 50 it initializes the size of the array.
* STK[size] sets a character array of defined size to implement the stack.
* top = -1 initializes the top of stack as empty.

**Functions:**

* push(char ch): Push function is used to insert an item into the stack.
* pop(): Pop function is used to remove an item from a stack.
* isMatching(char open, char close): This function checks if the opening parenthesis matches with the closing parenthesis.
* isBalanced(char exp[]): This function checks if the opening parenthesis has its matching closing parenthesis and returns
  whether the mathematical expression is balanced or not.
* main(): The main function performs the following operations:<br>
- Declares a character array to store the expression.<br>
- Accepts the expression from the user.<br>
- Calls the isBalanced() function.<br>
- Displays whether the expression is balanced or not.<br>
