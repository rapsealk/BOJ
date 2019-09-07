#include <stdio.h>

// (0, 0, 0) -> (r, c, 0) or (r, c, 1)
// int pose[][][];
typedef struct {
    int x, y;
} point_t;

point_t point[250000];

int main() {
    int N, Q, i;
    scanf("%d%d", &N, &Q);
    for (i = 0; i < N; i++) scanf("%d%d", &point[i].x, &point[i].y);
    return 0;
}