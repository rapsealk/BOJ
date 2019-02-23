#include <stdio.h>

int main()
{
	int N, i, j, k, max = 0;
	int A[1001], dp[1001] = { 0 };
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) scanf("%d", &A[i]);
	max = dp[1] = A[1];
	for (i = 1; i <= N; ++i) for (j = 1, k = 0; j < i; ++j) {
		if (A[i] > A[j] && dp[j] > dp[k]) k = j;
		dp[i] = dp[k] + A[i];
		if (max < dp[i]) max = dp[i];
	}
	printf("%d\n", max);
	return 0;
}
