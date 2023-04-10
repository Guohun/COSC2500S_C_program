/*
This is a recursion method based on C to solve the count blobs problem
@Guohun Zhu 

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
const int N = 5;

char blob[N][N] = {{0},{0}};
int visit[N][N];

void generateBlog(int n) {
	srand(time(NULL));   // Initialization, should only be called once.
	for (int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			double temp=(double)(rand() % 101) / 101;
			blob[i][j] = (temp > 0.55) ? '*' : ' ';
		}
}


int countBlog(int r, int c, int & G_num) {
	
	if (r <0 ||c<0) {
		return 0; 
	}
	if (visit[r][c] != -1) {
		return 0;
	}
	char value = blob[r][c];
	if (value != '*') {
		visit[r][c] = 0;
		return 0;
	}
	else {
		int sum[4] = { 0,0,0,0};
		if (r >= 1)    sum[0] = visit[r - 1][c];
		if (c >= 1)    sum[1] = visit[r ][c-1];
		if (c < N-1)   sum[2] = visit[r][c+1];
		if (r < N-1)   sum[3] = visit[r+1][c];
		int max_value = 0;
		for (int i = 0; i < 4; i++) if (max_value < sum[i]) max_value = sum[i];
		if (max_value > 0) visit[r][c] = max_value;
		else {
			visit[r][c] = ++G_num;
		}			
	}
	
	if (r < N-1)       countBlog(r + 1, c, G_num);
	if (c < N-1)     	countBlog(r, c + 1, G_num);
	if (r > 0) 	countBlog(r-1, c, G_num);
	if (c > 0) 	countBlog(r, c-1, G_num);
	return visit[r][c];
}
int main() {
	generateBlog(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", blob[i][j]);
			visit[i][j] = -1;
		}
		printf("\n");
	}
	int filled_num = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			countBlog(r, c, filled_num);

	printf("--number of blobs=%d--\n", filled_num);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", visit[i][j]);
		}
		printf("\n");
	}

	return 0;
}