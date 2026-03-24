#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void printArr(int* arr, int n, int piv, int piv_val, int front, int back)
{
	
	for(int i = 0; i<n; i++)
	{
		printf("%d\n", arr[i]);
	}

	printf("\nf: %d\nb: %d\npiv: %d\npiv_val: %d\n", front, back, piv, piv_val);


}

void quick_sort(int* arr, int len, int istart, int iend);


#define LENGTH 10
int main(int argc, char* argv[])
{
	srand(1);

	int raw_arr[LENGTH];
	for(int i = 0; i<LENGTH; i++)
	{
		raw_arr[i] = rand()%LENGTH;
	}

	int arr[LENGTH];
	int front = 0;
	int back = LENGTH-1;
	int pivot_idx = LENGTH/2;
	int pivot = raw_arr[pivot_idx];
	arr[pivot_idx] = pivot;

	for(int i = 0; i<LENGTH; i++)
	{
		if(i == pivot_idx) continue;

		if(raw_arr[i] <= pivot)
		{
			arr[front] = raw_arr[i];
			front++;
		}
		else {
			arr[back] = raw_arr[i];
			back--;
		}
	}

	front--;
	back++;


	printArr(arr,LENGTH,pivot_idx,pivot,front,back);


	




	return 0;
}

