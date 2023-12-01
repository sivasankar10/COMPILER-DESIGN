#include <stdio.h>

int main() {
    int a, b, c, result1, result2;

    // User input
    printf("Enter values for a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    // Common subexpression elimination
    int common = a * b;
    result1 = common + c;
    result2 = common - c;

    // Output results
    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}
