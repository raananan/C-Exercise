#include<stdio.h>
#include<stdlib.h>
#define N 5

int ** func(int mat[N][N]);
void printArray(int *arr, int size);

int main(){
	int **newmat;
	int mat[N][N] = {
			{ 1, 4, 5, 8, 2 },
			{ -8, 3, 7, 5, 3 },
			{ 17, 15, 7, 11, 9 },
			{ 3, 11, 15, 13, 11 },
			{ 17, 20, 21, 2, 19 }
	};
	int i,j;

	/*print original matrix*/
	for (i = 0; i < N; i++){
		printArray(mat[i], N);
		printf("\n");
	}

	/*call func*/
	newmat = func(mat);
	  
	/*print new matrix*/
	printf("\n\n");
	for (i = 0; i < N; i++){
		printArray(newmat[i], N);
		printf("\n");
	}
	/*free memory*/
	for (i = 0; i < N; i++)
		free(newmat[i]);
	free(newmat);


	system("pause");
	return 0;
}

int ** func(int mat[N][N]){
	int**newmat = NULL;
	int i, j, k,sum;
	if (!mat)return NULL;
	/*allocate new matrix   !!!! just copy it from notebook !!!!!!!*/
	newmat = (int **)malloc(sizeof(int *)*N);
	if (!newmat)return NULL;
	for (i = 0; i < N; i++){
		newmat[i] = (int*)malloc(sizeof(int)*N);
		if (!(newmat[i])){
			for (j = 0; j < i; j++)
				free(mat[j]);
			free(newmat);
			return NULL;
		}
	}
	/*logic*/
	for (i = 0; i < N; i++){ // scan all matrix elements
		for (j = 0; j < N; j++){
			sum = 0;
			/*row*/
			for (k = 0; k < j; k++) // sum elements in the same row
				sum += mat[i][k];
			/*col*/
			for (k = 0; k < i ; k++)// sum elements in the same col
				sum += mat[k][j];
			newmat[i][j] = sum; //update new matrix
		}
	}
	return newmat;
}

void printArray(int *arr, int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%4d ", arr[i]);
}