#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const double a = -10, b = 28, c = 8.0 / 3.0;
const int  Width = 80;
extern void fill_star(double x, double y, char*);

struct Vector3D{
    double x, y, z;
};

void lorenz(double xyz[], double dt) {
    double xt = xyz[0] + dt * a * (xyz[1] - xyz[0]);
    double yt = xyz[1] + dt * (xyz[0] * (b - xyz[2]) - xyz[1]);
    double zt = xyz[2] + dt * (xyz[0] * xyz[1] - c * xyz[2]);
    xyz[0] = xt; xyz[1] = yt; xyz[2] = zt;
}
void lorenz(struct Vector3D & input, double dt) {
    double xt = input.x + dt * a * (input.y - input.x);
    double yt = input.y + dt * (input.x * (b - input.z) - input.y);
    double zt = input.z + dt * (input.x * input.y - c * input.z);
    input.x = xt; input.y = yt; input.z = zt;
}
int main() {
    char* grid = (char*)malloc(sizeof(char) * Width * Width);
    for (char* p = grid; p < grid + Width * Width; p++) *p = 0;
    srand(time(NULL));   // Initialization, should only be called once.
    struct Vector3D xyz = { (double)(rand() % 101) / 101,
                        (double)(rand() % 71) / 71,
                        (double)(rand() % 127) / 127 };
    for (int i = 0; i < 8000; i++) {
        lorenz(xyz, 0.003);
        fill_star(xyz.z, xyz.x, grid);
    }
    int i = 0;
    for (char* p = grid; p < grid + Width * Width; p++) {
        printf("%c", (*p==0) ? ' ' : '*');
        if (i++ % Width == 0) printf("\n");
    }
    free(grid);

    getchar();
    return 0;
}

