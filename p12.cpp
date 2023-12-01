#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold an expression
struct Expression {
    char op;
    char arg1[10];
    char arg2[10];
    char result[10];
};

// Function to generate three-address code
void generateThreeAddressCode(const char *input) {
    struct Expression exp;
    int len = strlen(input);
    int index = 0;
    int tempVarCount = 1;

    for (int i = 0; i < len; i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            exp.op = input[i];
            exp.arg1[0] = input[i - 1];
            exp.arg1[1] = '\0';
            exp.arg2[0] = input[i + 1];
            exp.arg2[1] = '\0';
            snprintf(exp.result, sizeof(exp.result), "t%d", tempVarCount++);

            printf("%s = %s %c %s\n", exp.result, exp.arg1, exp.op, exp.arg2);

            // Update index for next operation
            i++;
        }
    }
}

int main() {
    char input[100];

    printf("Enter an expression: ");
    scanf("%[^\n]s", input);

    printf("Generating Three Address Code:\n");
    generateThreeAddressCode(input);

    return 0;
}

