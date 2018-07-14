// #12791 - Starman
#include <stdio.h>

int year[25] = { 1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974, 1975, 1976, 1977, 1977,
			  1979, 1980, 1983, 1984, 1987, 1993, 1995, 1997, 1999, 2002, 2003, 2013, 2016 };
char song[25][51] = { "DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
					"AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans", "StationToStation", "Low", "Heroes", "Lodger",
					"ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling",
					"Hours", "Heathen", "Reality", "TheNextDay", "BlackStar" };
int T, S, E, count;

int main(void)
{
	int i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &S, &E);
		count = 0;
		for (i = 0; i < 25; i++) if (S <= year[i] && year[i] <= E) count += 1;
		printf("%d\n", count);
		for (i = 0; i < 25; i++) if (S <= year[i] && year[i] <= E) printf("%d %s\n", year[i], song[i]);
	}
	return 0;
}