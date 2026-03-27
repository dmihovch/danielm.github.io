#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void printArr(int* arr, int istart, int iend)
{
	putchar('\n');
	for(int i = istart; i<=iend; i++)
	{
		if(i == istart)
		{
			printf("{ ");
		}
		if(i!=iend)
		{
			printf("%d, ", arr[i]);
		}
		if(i == iend)
		{
			printf("%d }", arr[i]);
		}
	}
	putchar('\n');
}


int quick_sort_calls = 0;

void quick_sort(int* arr, int len, int istart, int iend)
{
	quick_sort_calls++;

	if(len <= 1) return;
	
	int pivot = arr[iend];

	int probe = istart;
	int swap = istart-1;
	int tmp;
	while(probe < iend)
	{

		if(arr[probe] < pivot)
		{
			swap++;
			tmp = arr[probe];
			arr[probe] = arr[swap];
			arr[swap] = tmp;
			probe++;
		}
		else{
			probe++;
		}
	}
	int partition_idx = swap+1;
	tmp = arr[probe];
	arr[probe] = arr[partition_idx];
	arr[partition_idx] = tmp;
	int front_end = partition_idx-1;
	int back_start = partition_idx+1;
	quick_sort(arr,(front_end - istart) + 1,istart,front_end);
	quick_sort(arr,(iend - back_start + 1),back_start,iend);

}	


int main(int argc, char* argv[])
{
	srand(1);

	if(argc != 2)
	{
		printf("usage: ./qs NUMITEMS\n");
		return 1;
	}

	int length = atoi(argv[1]);

	int* arr = malloc(sizeof(int)*length);
	if(arr == NULL)
	{
		return -1;
	}

	for(int i = 0; i<length; i++)
	{
		arr[i] = rand()%length;
	}

	printArr(arr,0,length-1);

	quick_sort(arr,length,0,length-1);

	printArr(arr,0,length-1);

	free(arr);
	return 0;
}

