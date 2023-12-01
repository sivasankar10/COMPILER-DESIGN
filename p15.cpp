#include <stdio.h>

int main() {
    int n, i, j;
    char a[50][50];

    printf("Enter the number of intermediate code instructions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the 3 address code %d: ", i + 1);
        for (j = 0; j < 7; j++) {
            scanf(" %c", &a[i][j]); // Added space before %c to skip whitespace
        }
    }

    printf("The generated assembly code is:\n");
    for (i = 0; i < n; i++) {
        printf("MOV %c, R%d\n", a[i][3], i);
        if (a[i][4] == '-') {
            printf("SUB %c, R%d\n", a[i][5], i);
        }
        if (a[i][4] == '+') {
            printf("ADD %c, R%d\n", a[i][5], i);
        }
        if (a[i][4] == '*') {
            printf("MUL %c, R%d\n", a[i][5], i);
        }
        if (a[i][4] == '/') {
            printf("DIV %c, R%d\n", a[i][5], i);
        }
        printf("MOV R%d, %c\n", i, a[i][1]);
        printf("\n");
    }
    return 0;
}

