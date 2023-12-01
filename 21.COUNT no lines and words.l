%{
#include <stdio.h>
int charCount = 0;
int lineCount = 0;
int wordCount = 0;
int inWord = 0;
%}

%option noyywrap

%%

\n          { lineCount++; }
[a-zA-Z]+   { if (!inWord) { inWord = 1; wordCount++; } }
[^ \t\n]+   { charCount += yyleng; inWord = 0; }

%%

int main() {
    yylex();
    printf("Number of characters: %d\n", charCount);
    printf("Number of lines: %d\n", lineCount);
    printf("Number of words: %d\n", wordCount);
    return 0;
}
