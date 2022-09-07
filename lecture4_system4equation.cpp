#include <stdio.h>

const int ROWS = 3, COLS = 3;
double** init_2D(double disp[ROWS][COLS]) {
	/* 2D array declaration*/;
	double** p = (double**)disp;
	/*Counter variables for the loop*/
	printf("Enter %d decimals: ", ROWS * COLS);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%lf", &disp[i][j]);
		}
	}
	return p;
}

void disp_2D(double disp[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%6.2f\t", disp[i][j]);
		printf("\n");
	}
}

double* SolveEq(double A[ROWS][COLS], double B[ROWS]) {
	double x[ROWS];
	for (int second_row = 0; second_row < ROWS - 1; second_row++) {
		double pivot = A[second_row][second_row];
		for (int j = second_row; j < ROWS; j++)
			A[second_row][j] /= pivot;
		B[second_row] /= pivot;
		for (int i = second_row + 1; i < ROWS; i++)
		{
			double factor = A[i][second_row];
			for (int j = second_row; j <= ROWS; j++)
				A[i][j] -= factor * A[second_row][j];
			B[i] -= factor * B[second_row];
		}
	}

	x[ROWS - 1] = B[ROWS - 1] / A[ROWS - 1][ROWS - 1]; // X=B/A  last element

	for (int i = ROWS - 2; i >= 0; i--) {
		double sum = 0.0;
		for (int j = i + 1; j < ROWS; j++)
			sum += A[i][j] * x[j];
		x[i] = (B[i] - sum) / A[i][i];
	}
	return x;
}

int main() {
	double A[3][3]= {  { 111, 112,113 },
					   { 211,	212,213 }, 
					   { 221 , 231, 107 },
					   };
	double B[] = { 2, -6, 6 };
	disp_2D(A);

	double* x = SolveEq(A, B);
	printf("X=B/A\n");
	for (int i = 0; i < 3; i++) {
		printf("%6.4f\t", x[i]);
	}
	printf("\n");
	getchar();
	return 0;
}


