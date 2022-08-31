#include <stdio.h>
#include <math.h>



extern double myfunc_again(double x);  // global function
extern void  binary_search_roots();
extern double myexp(double x);

void henon_map(double xy[]) {
    double x_next = 1 - 1.4 * xy[0] * xy[0] + xy[1];
    double y_next = 0.3 * xy[0];
    xy[0] = x_next;
    xy[1] = y_next;
}
void plot_star(double y) {
    // -1.0:zero space   0: 40  space   1.0: 80 space
    for (int i = 0; i < 30 + y; i++)  printf(" ");
    printf("*\n");
}
int main() {
    double xy[]={0,0};  //initial
    for (int i = 0; i < 10000; i++) {
        henon_map(xy);
        plot_star(xy[0] * 40 + 40);
    }
    return 0;
}
