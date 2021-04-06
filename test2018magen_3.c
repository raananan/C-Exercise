#include<stdio.h>
#define N 4

void func(int mat[][N]) {
	int i, j, k, arr[N] = { 0 }, min, min_line = 0, max;
	for (i = 0; i < N; i++) {
		for (j = i - 1; j < i + 2 && j < N; j++) {
			if (j == -1) j++;
			for (k = i - 1; k < i + 2 && k < N; k++) {
				if (k == -1) k++;
				arr[i] += mat[j][k];
			}
		}
		if (!i) max = arr[i];
		else if (max < arr[i]) max = arr[i];
	}
	k = 0;
	while (k < N) {
		min = arr[0];
		for (i = 1; i < N; i++) {
			if (arr[i] < min) {
				min = arr[i];
				min_line = i;
			}

		}
		mat[k][k] = min;
		arr[min_line] = max + 1;
		min_line = 0;
		k++;
	}
}

int main() {
	int mat[N][N] = {
		{ 5,8,2,5 },
		{ 3,6,16,3 },
		{ -3,15,2,11 },
		{ 1,9,2,-1 }
	};

	func(mat);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			printf("%d	", mat[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}