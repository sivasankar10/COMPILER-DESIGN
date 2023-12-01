#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *input;
int pos = 0;
int error = 0;

void match(char c) {
    if (input[pos] == c) {
        pos++;
    } else {
        error = 1;
    }
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int factor() {
    int result = 0;
    if (isDigit(input[pos])) {
        result = input[pos] - '0';
        pos++;
    } else if (input[pos] == '(') {
        match('(');
        
        match(')');
    } else {
        error = 1;
    }
    return result;
}

int term() {
    int result = factor();
    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos++];
        int f = factor();
        if (op == '*') {
            result *= f;
        } else {
            if (f != 0) {
                result /= f;
            } else {
                error = 1;
                break; // Exit the loop when division by zero occurs
            }
        }
    }
    return result;
}

int expr() {
    int result = term();
    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos++];
        int t = term();
        if (op == '+') {
            result += t;
        } else {
            result -= t;
        }
    }
    return result;
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    int result = expr();
    if (error || input[pos] != '\0') {
        printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", result);
    }

    free(input);
    return 0;
}

