#include <stdio.h>
#include <math.h>
const float a = 5;

float f_2(float x) {
    return 3.6 * a + 3 / 5 * sin(x);
}

const float Pi = 3.14159;
int main()
{
    unsigned int r = 5;
    printf("r=%d   area1 =%6.4f\n", r, Pi * r * r);
    printf("r=%2d  area2 =%6.3f\n", r, Pi * r * r);
    printf("r=%4d  area3 =%16.14f\n", r, Pi * r * r);
    return 0;
}
