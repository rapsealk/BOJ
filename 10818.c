// #10818 - 최소, 최대
#include <stdio.h>

int MAX_VAL = -1000000;
int MIN_VAL = 1000000;

int main() {
    int N;
    int number;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &number);
        MAX_VAL = (MAX_VAL > number) ? MAX_VAL : number;
        MIN_VAL = (MIN_VAL < number) ? MIN_VAL : number;
    }
    printf("%d %d\n", MIN_VAL, MAX_VAL);
    return 0;
}