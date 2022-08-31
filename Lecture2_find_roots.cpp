#include <stdio.h>
#include <math.h>

const double GAP = 0.000000001;

const float Second = 0.6;       //global const
double myfunc(double x) {
    return sin(5*x) * sin(5*x) + Second *sin(3*x) -0.5;
}

#define  Pi  3.14159
#define  Shape  "Circle"
int main()
{
    //printf("%d %s area =%d\n", r, Shape, area);
   // const double python_output = -2.01237018;// 0.11521178;
   // printf("Python\toutput:\t f(%-10.9f) \t== %13.12f\n", python_output, myfunc(python_output));

    double error = 0;                //control the precision
    double input_x = -2.5;             // X range (-2, 2)
    const  double step = 0.00000001; //local const
    
    do {
        input_x += step;
        error = myfunc(input_x);
    } while ((error > GAP||error < -GAP)&& input_x<2.5);

    printf("C\toutput:\t f(%-10.9f) \t== %13.12f\n", input_x, error);
    return 0;
}