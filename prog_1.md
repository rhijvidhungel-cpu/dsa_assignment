Checking balance number of parenthesis

Objective:
The objective of this program is to analyze mathematical expression and check
if it has balanced number of parenthesis '()','{}','[]' or not.

Defining Data-Structures:
#define size 50
char STK[size];
int top = -1;

Explanation:
#define size 50 it initializes the size of the array
STK[size] sets a character array of defined size
top = -1 initializes the top of stack to be -1

Functions:
push(char ch): push function is used to insert an item into the stack.
pop(): Pop function is used to remove an item from a stack.
isMatching: This function checks if the opening parenthesis matches with the closing parenthesis.
isBalanced: This function checks if the opening parenthesis has its matching closing parenthesis and returns if the mathematical expression is balanced or not.
main(): The main function performs following operations:
- Declares a character array to store the expression
- Accepts the expression from the user
- Calls the isBalanced() function
- Displays whether the expression is balanced or not
