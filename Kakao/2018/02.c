#include <stdio.h>
#include <math.h>

int likes[501];

int main() {
    int N, K, i, j, k;
    double mean, variance, standard_deviation;
    double min_std = 10000000;
    scanf("%d%d", &N, &K);
    for (i = 1; i <= N; i++) scanf("%d", &likes[i]);
    for (i = 1; i <= N-(K-1); i++) {
        for (j = i+(K-1); j <= N; j++) {
            mean = variance = standard_deviation = 0.0;
            for (k = i; k <= j; k++) mean += likes[k];
            mean /= (j - i + 1);
            for (k = i; k <= j; k++) variance += pow(likes[k]-mean, 2);
            variance /= (j - i + 1);
            standard_deviation = sqrt(variance);
            min_std = (min_std < standard_deviation) ? min_std : standard_deviation;
        }
    }
    printf("%.11lf\n", min_std);
    return 0;
}