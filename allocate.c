#include<stdio.h>
#include<stdlib.h>
#define N 5
int *func(int matrix[N][N], int *size);
void printArray(int *arr, int size);

int main(){
	int *arr, size;
	int mat[N][N] = {
			{ 1, 4, 5, 8, 2 },
			{ -8, 3, 7, 5, 3 },
			{ 17, 15, 7, 11, 9 },
			{ 3, 11, 15, 13, 11 },
			{ 17, 20, 21, 2, 19 }
	};
	int i;
	for (i = 0; i < N; i++){
		printArray(mat[i], N);
		printf("\n");
	}
	arr = func(mat, &size);
	printf("\n\nThe array: %d\n", size);
	printArray(arr, size);
	printf("\n\n");
	free(arr);

	system("pause");
	return 0;
}
int *func(int matrix[N][N], int *size){
	int *newarr = NULL, i,j,k,flag=1;
	*size = 0;
	int temparr[2 * N];
	if (!matrix){
		return NULL; 
	}
	for (i = 0; i < N; i++){  //insert diagonals to temparray
		temparr[i] = matrix[i][i]; //main diagonal
		temparr[N + i] = matrix[i][N - i - 1]; //secoundary diagonal
	}
	*size = 2 * N ;
	newarr = (int*)malloc(sizeof(int)**size);
	k = 0;
	for (i = 0; i < 2 * N;i++){ //scan all diagonals
		flag = 1;
		for (j =0; flag && j < k; j++){
			if (newarr[j] == temparr[i]){
				flag = 0;
				break;
			}
		}
		if (flag){ //insert if no repeat
			newarr[k++] = temparr[i];
		}
	}
	*size = k;
	newarr = (int*)realloc(newarr,sizeof(int)*k);
	return newarr;	
}

void printArray(int *arr, int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%4d ", arr[i]);
}