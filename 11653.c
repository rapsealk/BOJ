// #11653 - 소인수분해
#include <stdio.h>

int main() {
    int N, i = 2;
    scanf("%d", &N);
    while (N > 1) {
        if (N % i == 0) {
            printf("%d\n", i);
            N /= i;
        } else i++;
    }
    return 0;
}