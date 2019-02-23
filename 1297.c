#include <stdio.h>
#include <math.h>

int main()
{
    int d, hr, wr;
    double x;
    scanf("%d%d%d", &d, &hr, &wr);
    x = sqrt((double) (d * d) / (hr * hr + wr * wr));
    printf("%d %d\n", (int) (hr * x), (int) (wr * x));
    return 0;
}