#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLen - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix[prefixIndex++] = c;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[prefixIndex++] = pop();
            }
            if (top != -1 && stack[top] == ')') {
                pop(); // Pop the closing parenthesis
            }
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                prefix[prefixIndex++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        prefix[prefixIndex++] = pop();
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the correct order
    int start = 0, end = prefixIndex - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
