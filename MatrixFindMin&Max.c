#include<stdio.h>

int n=4;
void calcmat(int mat[n][n]);
int main(){
	int n=4;
	int mat[4][4]={{8,5,2,9},
				   {3,2,1,0},		
				   {5,4,4,3},
				   {7,9,3,1}};

	calcmat(mat);
	
	return 0;
}
void calcmat(int mat[n][n]){
	int min, max, minline=0, maxline=0, sum=0, amount=0, i, j=0;
	
	for(i=0;i<n;i++){
		sum+=mat[j][i];
	}
	max=sum;
	min=sum;

	for(i=1;i<n;i++){
		sum=0;
		for(j=0;j<n;j++){
			sum+=mat[i][j];
			if(j==n-1){
				if(sum>max){
					max=sum;
					maxline=i;
				}
				if(sum<min){
					min=sum;
					minline=i;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		amount+=mat[i][i];
	}
	for(i=0;i<n;i++){
		amount+=mat[n-1-i][i];
	}
	printf("maxline is line number %d and max sum is %d\n", maxline+1, max);
	printf("minline is line number %d and min sum is %d\n", minline+1, min);
	printf("total amount of both alachsonim is %d\n", amount);
}
