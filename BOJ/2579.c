#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int step[301];
int dp[301][2];

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &step[i]);
    }
    dp[1][0] = step[1];
    for (i = 2; i <= N; i++) {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + step[i];
        dp[i][1] = dp[i-1][0] + step[i];
    }
    printf("%d\n", max(dp[N][0], dp[N][1]));
    return 0;
}