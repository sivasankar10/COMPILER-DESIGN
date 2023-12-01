%{
#include <stdio.h>
int commentLines = 0;
FILE *outputFile;
%}

%option noyywrap

%%

"/*"                { commentLines++; while (1) { if (strstr(yytext, "*/")) break; else yylex(); } }
"//"                { commentLines++; while (yytext[0] != '\n') yylex(); }

[^/\n]+             { fprintf(outputFile, "%s", yytext); }
"/"                 { fprintf(outputFile, "%s", yytext); }
"\n"                { fprintf(outputFile, "\n"); }

%%

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        printf("Error opening output file.\n");
        fclose(file);
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);
    fclose(outputFile);

    printf("Number of comment lines: %d\n", commentLines);
    printf("Non-comment lines written to %s\n", argv[2]);

    return 0;
}
