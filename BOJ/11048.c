// #11048 - 이동하기
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int map[1001][1001];
int dp[1001][1001];

int main() {
    int i, j;
    int N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) scanf("%d", &map[i][j]);
    for (i = 1; i <= N; i++) dp[i][1] = dp[i-1][1] + map[i][1];
    for (j = 1; j <= M; j++) dp[1][j] = dp[1][j-1] + map[1][j];
    for (i = 2; i <= N; i++) for (j = 2; j <= M; j++) {
        dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1])) + map[i][j];
    }
    printf("%d\n", dp[N][M]);
    return 0;
}