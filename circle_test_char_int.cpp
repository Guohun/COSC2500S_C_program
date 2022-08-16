// triangle_area.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>


const float a = 5;
float f(float x) {
    return 3.6 * a + 3 / 5 * sin(x);
}


//#define Pi 3.14159

int main_back()
{
#define Shape "Rectangle"

    const float Pi = 3.14159;
    unsigned char r = 50;
    int  area = Pi * r * r;
    printf("when r=%d  %s area =%d\n", r, Shape, area);



    unsigned char l_r = 500;
    int large_area = Pi * l_r * l_r;
    printf("when r=%d  large circle area =%d\n",
        l_r, large_area);
    return 0;
}

/*
int base = 10;
int high = 5;
printf("area=%d\n", base* high / 2);
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
