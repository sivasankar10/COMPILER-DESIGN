#include <stdio.h>
#include <ctype.h>

int main() {
	int i;
    char input[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s",&input);
    printf("Operators found: ");
    for (i = 0; input[i] != '\0'; i++)
	 {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("%c ", input[i]);
        }
    }

    return 0;
}
