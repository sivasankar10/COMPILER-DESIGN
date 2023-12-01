%{
#include <stdio.h>
int line_num = 1;
%}

%option noyywrap

%%

\n      { printf("%d: %s", line_num++, yytext); }
.       { printf("%s", yytext); }

%%

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);

    return 0;
}
