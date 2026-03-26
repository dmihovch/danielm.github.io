#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void printArr(int* arr, int istart, int iend)
{
	for(int i = istart; i<=iend; i++)
	{
		printf("idx = %d, val = %d\n",i, arr[i]);
	}

}


int quick_sort_calls = 0;

void quick_sort(int* arr, int len, int istart, int iend)
{
	quick_sort_calls++;
	printf("\n===== %d QUICK SORT CALL =====\n",quick_sort_calls);

	if(len <= 1) return;
	
	int pivot = arr[(len/2) + istart];
	printArr(arr,istart,iend);
	printf("pivot = %d\n",pivot);

	int swap = iend;
	int tmp;
	for(int i = istart; i <= iend; i++)
	{
		if(arr[i] > pivot)
		{
			tmp = arr[i];
			arr[i] = arr[swap];
			arr[swap] = tmp;
			swap--;
		}
	}
	tmp = arr[istart];
	arr[istart] = arr[swap];
	arr[swap] = tmp;
	
	printf("post sorting:\n");
	printArr(arr,istart,iend);
	quick_sort(arr,len/2,istart,istart+(len/2));
	quick_sort(arr,len/2,istart+(len/2)+1,iend);

}	

	


#define LENGTH 10
int main(int argc, char* argv[])
{
	srand(1);

	int arr[LENGTH];
	for(int i = 0; i<LENGTH; i++)
	{
		arr[i] = rand()%LENGTH;
	}


	quick_sort(arr,LENGTH,0,LENGTH-1);

	printArr(arr,0,9);



	




	return 0;
}

