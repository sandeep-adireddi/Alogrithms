/*


countingSort

O(n)

*/
#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[],int size, int maxValue)
{
	int temp[1000000]={0},sorted[100000];
	for (int i = 0; i < size; ++i)
	{
		temp[array[i]] = temp[array[i]] + 1;                    // gives number of particular element present in input

		
	}
	
	for (int i = 1; i <= maxValue; ++i)
	{
		temp[i]= temp[i]+temp[i-1];								// gives position of element in the stored array
		
	}
	for (int i = size-1; i >= 0 ; --i)
	{
		sorted[temp[array[i]]] = array[i];
		temp[array[i]] = temp[array[i]] - 1;				   // putting elemtes into thier postions in sorted array
		
	}
	for (int i = 1; i <= size; ++i)
	{
		printf("%d ", sorted[i] );								// print to sorted array
		
	}
}

int main()
{	


int arraySize = 0,maxValue = 0;
scanf("%d",&arraySize);
scanf("%d",&maxValue);+

int array[10000];

for (int i = 0; i < arraySize; ++i)
{
	scanf("%d",&array[i]);    //storing elements in array

	
}

countingSort(array,arraySize,maxValue);
	
	return 0;
}