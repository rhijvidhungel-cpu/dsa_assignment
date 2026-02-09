#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
typedef struct {
    char items[MAX];
    int top;
} CharStack;

// Stack structure for operands
typedef struct {
    int items[MAX];
    int top;
} IntStack;

// Function prototypes
void initCharStack(CharStack *s);
void pushChar(CharStack *s, char c);
char popChar(CharStack *s);
char peekChar(CharStack *s);
int isEmptyChar(CharStack *s);

void initIntStack(IntStack *s);
void pushInt(IntStack *s, int n);
int popInt(IntStack *s);
int isEmptyInt(IntStack *s);

int precedence(char op);
void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single digit numbers, no spaces): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}

// ---------------- Char Stack functions ----------------
void initCharStack(CharStack *s) {
    s->top = -1;
}

void pushChar(CharStack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = c;
    }
}

char popChar(CharStack *s) {
    if (s->top >= 0) return s->items[(s->top)--];
    return '\0';
}

char peekChar(CharStack *s) {
    if (s->top >= 0) return s->items[s->top];
    return '\0';
}

int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

// ---------------- Int Stack functions ----------------
void initIntStack(IntStack *s) {
    s->top = -1;
}

void pushInt(IntStack *s, int n) {
    if (s->top < MAX - 1) s->items[++(s->top)] = n;
}

int popInt(IntStack *s) {
    if (s->top >= 0) return s->items[(s->top)--];
    return 0;
}

int isEmptyInt(IntStack *s) {
    return s->top == -1;
}

// ---------------- Utility functions ----------------
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ---------------- Convert infix to postfix ----------------
void infixToPostfix(char infix[], char postfix[]) {
    CharStack s;
    initCharStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isdigit(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            pushChar(&s, c);
        } else if (c == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[k++] = popChar(&s);
            }
            popChar(&s); // Remove '('
        } else { // Operator
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(c)) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, c);
        }
    }

    while (!isEmptyChar(&s)) {
        postfix[k++] = popChar(&s);
    }

    postfix[k] = '\0';
}

// ---------------- Evaluate postfix expression ----------------
int evaluatePostfix(char postfix[]) {
    IntStack s;
    initIntStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            pushInt(&s, c - '0');
        } else { // Operator
            int b = popInt(&s);
            int a = popInt(&s);
            switch (c) {
                case '+': pushInt(&s, a + b); break;
                case '-': pushInt(&s, a - b); break;
                case '*': pushInt(&s, a * b); break;
                case '/': pushInt(&s, a / b); break;
            }
        }
    }

    return popInt(&s);
}
