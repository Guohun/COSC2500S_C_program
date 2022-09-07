#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double myfunc_again(double x) {
    return 0;
}  // global function
/*
extern void  binary_search_roots();
extern double myexp(double x);

void henon_map(double xy[]) {
    double x_next = 1 - 1.4 * xy[0] * xy[0] + xy[1];
    double y_next = 0.3 * xy[0];
    xy[0] = x_next;
    xy[1] = y_next;
}*/
void plot_star(double y) {
    // -1.0:zero space   0: 40  space   1.0: 80 space
    for (int i = 0; i < 30 + y; i++)  printf(" ");
    printf("*\n");
}


void henon_map(double& x, double& y) {
    double x_next = 1 - 1.4 * x * x + y;
    double y_next = 0.3 * x;
    x = x_next;
    y = y_next;
}

/*
 x   axis    -1:   1      extends to  0   60
 y   axis   -0.4: 0.4     extends to  0   60
*/
const int  Width=60;
void fill_star(double x, double y, char* grid) {
    int i_loc = (int)(x * Width   + Width/2) % Width ;
    int j_loc = (int)(y * Width /2   + Width/ 2) % Width;
    (*(grid + i_loc * Width + j_loc))++;
}

int main() {
    char* grid = (char*) malloc(sizeof(char) * Width * Width);
    double x = 0, y = 0;
    for (char* p = grid; p < grid + Width * Width; p++) *p =0;
    for (int i = 0; i < 1000; i++) {
        henon_map(x, y);
        fill_star(y, x, grid);
    }
    int i = 0;
    for (char* p = grid; p < grid + Width * Width; p++) {
        printf("%c", (* p == 0 )?' ':('0' + *p));
        if (i++%Width==0) printf("\n");
    }
    free(grid);
    getchar();
    return 0;
}
