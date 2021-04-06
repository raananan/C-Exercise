#include<stdio.h>

int n=4;
int matrixcheck(int mat[n][n]);
int main(){
	int matrix[4][4]={{4,2,8,0},
					  {3,5,7,3},
					  {2,2,8,6},
					  {1,5,3,1}};
	
	printf("%d", matrixcheck(matrix));
	
	return 0;
}
int matrixcheck(int mat[n][n]){
	int row, col, zugicheck, sumrow, status=1;	
	
	for(row=0;row<n;row++){
		zugicheck=mat[row][0]%2;
		sumrow=0;
		for(col=0;col<n;col++){
			sumrow+=mat[row][col];
			if(mat[row][col]>9 || mat[row][col]<0){
				status=0;
				break;
			}
			if(col==n-1){
				if(sumrow>=n*5){
					status=0;
					break;
				}
			}
			if(mat[row][col]%2!=zugicheck){
				status=0;
				break;
			}
		}
	}
	return status;
}
