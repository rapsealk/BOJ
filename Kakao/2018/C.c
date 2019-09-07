#include <stdio.h>
#include <string.h>

int isVariable[100];
char variable[100][100];
char integer[100][12];
char operator[100][3];
char conditional_statement[1000001];

int main() {
    int i = 0, j = 0, len = 0;
    scanf("%s", conditional_statement);
    len = strlen(conditional_statement);
    printf("len: %d\n", len);
    while (i < len) {
        printf("%d < len(%d)\n", i, len);
        for (j = i; j < len && (conditional_statement[j] != '&' || conditional_statement[j+1] != '&'); j++);
        // i = strcmp(conditional_statement+i, "&&");
        printf("j: %d\n", j);
        conditional_statement[j] = '\0';
        printf("token: %s\n", conditional_statement+i);
        i = j+2;
    }
    return 0;
}