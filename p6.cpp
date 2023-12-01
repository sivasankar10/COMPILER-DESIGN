#include <stdio.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 100

char productions[MAX_RULES][MAX_LEN];
char nonTerminal;

void eliminateLeftRecursion(int n) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) {
            char alpha[MAX_LEN], beta[MAX_LEN];
            int alphaCount = 0, betaCount = 0;

            int j = 3; // Skip A -> part
            while (productions[i][j] != '|' && productions[i][j] != '\0') {
                alpha[alphaCount++] = productions[i][j++];
            }
            alpha[alphaCount] = '\0';

            if (productions[i][j] == '|') {
                j++; // Skip the '|'
                while (productions[i][j] != '\0') {
                    beta[betaCount++] = productions[i][j++];
                }
                beta[betaCount] = '\0';

                printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
                printf("%c' -> %s%c' | epsilon\n", nonTerminal, alpha, nonTerminal);
            } else {
                printf("%c -> %s%c'\n", nonTerminal, productions[i] + 3, nonTerminal);
                printf("%c' -> epsilon\n", nonTerminal);
            }
        } else {
            printf("%s\n", productions[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);
    printf("Enter the production rules (format: A -> alpha | beta): \n");

    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("Enter the non-terminal to eliminate left recursion for: ");
    scanf(" %c", &nonTerminal);

    printf("Productions after left recursion elimination:\n");
    eliminateLeftRecursion(n);

    return 0;
}

