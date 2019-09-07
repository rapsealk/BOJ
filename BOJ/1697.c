// #1697
#include <stdio.h>

typedef struct {
    int x;
    int time;
} hist_t;

hist_t q[300001];
int c[100001];

int main()
{
    int N, K;
    int head = 0, tail = 0;
    hist_t p;
    scanf("%d%d", &N, &K);
    q[tail].x = K;
    q[tail++].time = 0;
    while (head < tail) {
        p = q[head++];
        if (p.x < 0 || 100000 < p.x || c[p.x]) continue;
        c[p.x] = 1;
        if (p.x == N) {
            printf("%d\n", p.time);
            break;
        }
        q[tail].x = p.x - 1;
        q[tail++].time = p.time + 1;
        q[tail].x = p.x + 1;
        q[tail++].time = p.time + 1;
        if (p.x % 2 == 0) {
            q[tail].x = p.x / 2;
            q[tail++].time = p.time + 1;
        }
    }
    return 0;
}