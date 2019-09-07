#include <stdio.h>

int _2017_prize[7] = { 5000000, 3000000, 2000000, 500000, 300000, 100000, 0 };
int _2017_numbers[7] = { 1, 2, 3, 4, 5, 6, 79 };
int _2018_prize[6] = { 5120000, 2560000, 1280000, 640000, 320000, 0 };
int _2018_numbers[6] = { 1, 2, 4, 8, 16, 33 };

int main() {
	int T, a, b, i;
	int _2017_rank, _2018_rank;
	int total_prize;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		_2017_rank = _2018_rank = i = 1;
		total_prize = 0;
		while (a > _2017_rank && i < 7) _2017_rank += _2017_numbers[i++];
		if (a > 0) total_prize += _2017_prize[i-1];
		i = 1;
		while (b > _2018_rank && i < 6) _2018_rank += _2018_numbers[i++];
		if (b > 0) total_prize += _2018_prize[i-1];
		printf("%d\n", total_prize);
	}
	return 0;
}