#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    else
        return 0;
}

int main() {
    char infix[50], postfix[50];
    int i, k = 0;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        if ((infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[k++] = infix[i];
        }

        else if (infix[i] == '(') {
            push(infix[i]);
        }

        else if (isOperator(infix[i])) {
            push(infix[i]);
        }

        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

