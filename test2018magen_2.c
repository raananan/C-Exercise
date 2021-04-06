#include<stdio.h>
#include<stdlib.h>

int *func(int *arr1, int *arr2, int *size) {
	int i = 1, j = 1, evenCounter = 0, oddCounter = 0;
	int *new_arr;
	*size = 0;
	if (arr1[0] % 2) oddCounter++;
	if (arr2[0] % 2) oddCounter++;
	while (arr1[i] != -1 && arr1[i] > arr1[i - 1]) if (arr1[i++] % 2) oddCounter++;
	while (arr2[j] != -1 && arr2[j] > arr2[j - 1]) if (arr2[j++] % 2) oddCounter++;
	if (arr1[i] != -1 || arr2[j] != -1) return NULL;
	(*size) = i + j;
	new_arr = (int*)malloc(sizeof(int) * (*size));
	if (!new_arr) return NULL;
	i = 0, j = 0;
	while (i + j != *size) {
		if (arr1[i] < arr2[j] && arr1[i] != -1) {
			if (arr1[i] % 2) new_arr[evenCounter++] = arr1[i++];
			else new_arr[oddCounter++] = arr1[i++];
		}
		else if (arr2[j] != -1) {
				if (arr2[j] % 2) new_arr[evenCounter++] = arr2[j++];
				else new_arr[oddCounter++] = arr2[j++];
		}
	}

	return new_arr;
}

int main() {
	int arr1[] = { 1,5,8,12,62,91,-1 };
	int arr2[] = { 2,16,17,19,21,64,65,71,76,90,103,-1 };
	int size = 0;
	int *new_arr = func(arr1, arr2, &size);

	for (int i = 0; i < size; i++)
		printf("%d, ", new_arr[i]);
	printf("\n");

	system("pause");
	return 0;
}