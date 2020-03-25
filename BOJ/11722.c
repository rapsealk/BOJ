#include <stdio.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))

int dp[1000];

int main()
{
    int N, A[1000], i, j = 0, result = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++) {
        dp[i] = 1;
        for (j = i-1; j >= 0; j--) if (A[j] > A[i] && dp[i] <= dp[j]) {
            dp[i] = dp[j] + 1;
        }
    }
    for (i = 0; i < N; i++) {
        result = MAX(result, dp[i]);
    }
    printf("%d\n", result);
    return 0;
}