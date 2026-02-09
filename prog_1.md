#include <stdio.h>

#define size 50
char STK[size];
int top = -1;

void push(char ch) {
    if (top < size - 1) STK[++top] = ch;
}

char pop() {
    if (top >= 0) return STK[top--];
    return '\0';
}

int isMatching(char open, char close) {
    if (open=='(' && close==')') return 1;
    if (open=='{' && close=='}') return 1;
    if (open=='[' && close==']') return 1;
    return 0;
}

int isBalanced(char exp[]) {
    for(int i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(top==-1 || !isMatching(pop(), exp[i])) return 0;
        }
    }
    return top==-1;
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    fgets(exp, sizeof(exp), stdin);

    if(isBalanced(exp)) printf("Expression is BALANCED\n");
    else printf("Expression is NOT BALANCED\n");
    return 0;
}
