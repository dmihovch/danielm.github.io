#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void printArr(int* arr, int istart, int iend)
{
	putchar('\n');
	for(int i = istart; i<=iend; i++)
	{
		printf("idx: %d, val: %d\n",i, arr[i]);
	}
	putchar('\n');

}



void quick_sort(int* arr, int len, int istart, int iend)
{
	if(len <= 1) return;
	
	int pivot = arr[(len/2) + istart];
	int swap = iend;
	int tmp;
	for(int i = iend; i >= istart; i--)
	{
		if(arr[i] > pivot)
		{
			tmp = arr[i];
			arr[i] = arr[swap];
			arr[swap] = tmp;
			// arr[i] ^= arr[swap];
			// arr[swap] ^= arr[i];
			// arr[i] ^= arr[swap];
			swap--;
		}
	}
	tmp = arr[istart];
	arr[istart] = arr[swap];
	arr[swap] = tmp;
	
	// arr[istart] ^= arr[swap];
	// arr[swap] ^= arr[istart];
	// arr[istart] ^= arr[swap];


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




	




	return 0;
}

