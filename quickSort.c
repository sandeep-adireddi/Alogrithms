/*
quickSort
divide and conqure basied algorithm
best case =  T(n) = 2T(n/2) + theta(n)
average case =  T(n) = T(n/9) + T(9n/10) + theta(n)
worst case =  T(n) = T(n-1) + theta(n)
runtime O(nlogn)

*/
#include <stdio.h>
#include <stdlib.h>


int partion(int *array,int start,int end)
{
	int pivot = *(array + end);
	int j = start-1;
	for (int i = start; i <= end-1 ; ++i)
	{
		if (*(array + i) <= pivot)
		{
			j=j+1;
			int temp=*(array+j);
			*(array +j ) = *(array + i);
			*(array + i) = temp;
		}
		/* code */
	}
	int temp = *(array+j+1);
	*(array+j+1) = *(array + end);
	*(array + end) = temp;
	return j+1;
}

int quickSort(int *array,int start, int end)
{
	if (start<end)
	{  int middle = partion(array,start,end);
		quickSort(array,start,middle-1);
		quickSort(array,middle+1,end);
		/* code */
	}
}
int main()
{	
int arraySize = 0;
scanf("%d",&arraySize);
int *array = (int*) malloc(arraySize * sizeof(int));  // initailzation of array of input size 

for (int i = 1; i <= arraySize; ++i)
{
	scanf("%d",array + i);    //storing elements in array

	
}

quickSort(array,1,arraySize); //calling quicksort

for (int i = 1; i <= arraySize; ++i)
{
	printf("%d\n",*(array + i));        // printing the sorted array
	
}
	/* code */
	return 0;
}