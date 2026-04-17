%{
#include <stdio.h>
int lines = 0, tabs = 0, spaces = 0;
%}

%%
\n      { lines++; }
\t      { tabs++; }
[ ]     { spaces++; }
.       { ; }
%%

int main() {
    printf("Enter input (Ctrl+Z then Enter to finish):\n");
    yylex();
    printf("\nLines: %d\nTabs: %d\nSpaces: %d\n", lines, tabs, spaces);
    return 0;
}

int yywrap() {
    return 1;
}