#include <stdio.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 100

char productions[MAX_RULES][MAX_LEN];
char nonTerminal;

void eliminateLeftFactoring(int n) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) {
            int maxPrefixLength = 0;
            int len = strlen(productions[i]);

            for (int j = i + 1; j < n; j++) {
                int k = 3; // Skip the non-terminal part
                int prefixLength = 0;
                while (productions[i][k] == productions[j][k] && productions[i][k] != '\0') {
                    prefixLength++;
                    k++;
                }

                if (prefixLength > maxPrefixLength) {
                    maxPrefixLength = prefixLength;
                }
            }

            if (maxPrefixLength > 0) {
                printf("%c -> %.*s%c'\n", nonTerminal, maxPrefixLength, productions[i] + 3, nonTerminal);
                printf("%c' -> ", nonTerminal);
                for (int l = i; l < n; l++) {
                    int k = 3 + maxPrefixLength;
                    if (productions[l][k] == '\0' || productions[l][0] != nonTerminal) {
                        printf("%s%c' | ", productions[l] + 3 + maxPrefixLength, nonTerminal);
                    }
                }
                printf("epsilon\n");
            } else {
                printf("%s\n", productions[i]);
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

    printf("Enter the non-terminal to eliminate left factoring for: ");
    scanf(" %c", &nonTerminal);

    printf("Productions after left factoring elimination:\n");
    eliminateLeftFactoring(n);

    return 0;
}

