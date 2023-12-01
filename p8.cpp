#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

// Structure to represent a symbol entry
typedef struct {
    char name[50];
    int address;
} SymbolEntry;

SymbolEntry symbolTable[MAX_SYMBOLS]; // Array to hold symbol entries
int symbolCount = 0; // Counter to track the number of symbols in the table

// Function to insert a new symbol into the table
void insertSymbol(const char *name, int address) {
    if (symbolCount < MAX_SYMBOLS) {
        SymbolEntry newSymbol;
        strcpy(newSymbol.name, name);
        newSymbol.address = address;

        symbolTable[symbolCount++] = newSymbol;
        printf("Symbol inserted successfully.\n");
    } else {
        printf("Symbol table full. Cannot insert more symbols.\n");
    }
}

// Function to search for a symbol in the table
int searchSymbol(const char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Symbol found:\nName: %s\nAddress: %d\n", symbolTable[i].name, symbolTable[i].address);
            return 1; // Symbol found
        }
    }
    printf("Symbol not found in the table.\n");
    return 0; // Symbol not found
}

// Function to display all symbols in the table
void displaySymbols() {
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Address: %d\n", symbolTable[i].name, symbolTable[i].address);
    }
}

int main() {
    int choice;
    char name[50];
    int address;

    do {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert a symbol\n");
        printf("2. Search for a symbol\n");
        printf("3. Display all symbols\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter symbol name: ");
                scanf("%s", name);
                printf("Enter symbol address: ");
                scanf("%d", &address);
                insertSymbol(name, address);
                break;
            case 2:
                printf("Enter symbol name to search: ");
                scanf("%s", name);
                searchSymbol(name);
                break;
            case 3:
                displaySymbols();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

