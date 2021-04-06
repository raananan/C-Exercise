#include<stdio.h>

void func(int arr[], int size);

void print(int arr[], int size);
void shift_left_arr(int*arr, int size);

int main(){
	int arr[] = { -3, 2, 5, 21, 23, 24, 36, 37, 48, 50 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	//shift_left_arr(arr, size);

	func(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}


void func(int arr[], int size){
	int i, current_index = 0, dest_index = size - 1, temp;

	while (current_index <dest_index){
		//if odd move to the next one
		if (arr[current_index] % 2){
			current_index++;
			continue;
		}
		// if even (it's the  smaller one ) move it to the end
		temp = arr[current_index];
		for (i = current_index; i < dest_index; i++) //shift left
			arr[i] = arr[i + 1];
		arr[i] = temp;
		dest_index--;
	}
}


	

void print(int arr[], int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%4d ", arr[i]);
	printf("\n");
}









void shift_left_arr(int*arr, int size){
	int temp, i;
	temp = *arr;
	for (i = 0; i < size-1; i++)
		*(arr + i) = *(arr + i + 1);
	*(arr + i) = temp;
}