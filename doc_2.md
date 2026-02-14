# Checking balance number of parenthesis

## Objective:
The objective of this program is to convert a mathematical expression from infix notation to postfix notation and evaluate its result.

### Defining Data-Structures:
```c
#define MAX 100
typedef struct {
    char items[MAX];
    int top;
} CharStack;

typedef struct {
    int items[MAX];
    int top;
}IntStack;
```

**Explanation:**
* CharStack is used to store operators during the    conversion from infix to postfix.
* IntStack is used to store operands while evaluating the postfix expression.
* top is initialized to -1 for both stacks to indicate that they are empty.
* MAX defines the maximum size of the stack.

**Functions:**
* initCharStack(CharStack *s): Initializes a character stack.

* pushChar(CharStack *s, char c): Pushes a character onto the operator stack.

* popChar(CharStack *s): Pops a character from the operator stack.

* peekChar(CharStack *s): Returns the top element of the operator stack without removing it.

* isEmptyChar(CharStack *s): Checks if the operator stack is empty.

* initIntStack(IntStack *s): Initializes an integer stack.

* pushInt(IntStack *s, int n): Pushes an integer onto the operand stack.

* popInt(IntStack *s): Pops an integer from the operand stack.

* isEmptyInt(IntStack *s): Checks if the operand stack is empty.

* precedence(char op): Returns the precedence of an operator.

* infixToPostfix(char infix[], char postfix[]): Converts an infix expression to postfix notation.

* evaluatePostfix(char postfix[]): Evaluates a postfix expression and returns the result.

* main(): The main function performs the following operations:<br>

* Accepts an infix expression from the user (single-digit numbers, no spaces).<br>

* Calls infixToPostfix() to convert it into postfix form.<br>

* Displays the postfix expression.<br>

* Calls evaluatePostfix() to calculate the result.<br>

* Displays the evaluation result.<br>

**Sample Output:**
Enter infix expression (single digit numbers, no spaces): 2+4  
Postfix expression: 24+
Postfix expression: 24+
Evaluation result: 6
