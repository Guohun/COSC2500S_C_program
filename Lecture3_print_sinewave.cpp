#include <stdio.h>
#include <math.h>


const float Second = 0.6;       //global const
double myfunc_again(double x) {
    return sin(5 * x) * sin(5 * x) + 
        Second * sin(3 * x) - 0.5;
}
int main() {
    const float step = 0.05;    //local const
    float x = 0.5;              //initilize 
    while (x<=2) {
        x += step;              // x =x+ step
        printf("%3.2f\t%3.2f\n",x,myfunc_again(x));
    } 
    return 0;
}