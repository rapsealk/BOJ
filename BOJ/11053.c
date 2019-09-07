#include <stdio.h>

int main()
{
	int N, i, j, max = 1;
	int A[1000], dp[1000] = { [0 ... 999] = 1 };
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", &A[i]);
	for (i = 0; i < N; ++i) for (j = 0; j < i; ++j) {
		if (A[i] > A[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
		if (max < dp[i]) max = dp[i];
	}
	printf("%d\n", max);
	return 0;
}
