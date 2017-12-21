/*
Heap sort


best case= O(nlogn)
average case=O(nlogn)
worst case= O(nlogn) 


heapify runtime = O(logn)

BuildHeap runttime = o(n) (look http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf for clarity)

buildheap equation = t(2n/3) + O(1)

*/


#include <stdio.h>
#include <stdlib.h>

void heapify(int *array,int index, int heapSize)
{
int largest = index;
if (2*(index) <= heapSize && *(array+index) < *(array+(2*index)))           // cheack if left is biggest
{

	largest = 2*index;
}

if (2*(index)+1 <= heapSize && *(array+index) < *(array+(2*index)+1))    // cheack if right is biggest
{

	largest = 2*index+1;
}
if (largest != index)													// replacing the bigger number to root if any
{
	int temp = *(array + largest);
	*(array + largest) = *(array + index);
	*(array + index) = temp;
	heapify(array,largest,heapSize);                                     // calling heapify agian to correct the bottom sub tree 
}

}

void buildHeap(int *array,int arraySize)
{
	for (int i = arraySize/2; i >= 1; --i)
	{
		heapify(array,i,arraySize);
		
	}
}


void heapSort(int *array,int arraySize)
{	
	int heapSize = arraySize;
	buildHeap(array,heapSize);             // making the heap for first time
	for (int i = heapSize; i >=2; --i)
	{
		int temp   = *(array+1);			// swaping the highest element to last
		*(array+1) = *(array+i);
		*(array+i) = temp;
		arraySize  = arraySize-1;			//  this is for skiping last elements because they are sorted
		heapify(array,1,arraySize);			// heapify the rest of elements 
		 	
	
	}
}

int main()
{	
int arraySize = 0;
scanf("%d",&arraySize);
int *array = (int*) malloc((arraySize+1) * sizeof(int));  // initailzation of array of input size 

for (int i = 1; i <= arraySize; ++i)
{
	scanf("%d",array + i);    //storing elements in array
	
}


heapSort(array,arraySize); //calling heapsort

for (int i = 1; i <= arraySize; ++i)
{
	printf("%d ",*(array + i));        // printing the sorted array
	
}
	
	return 0;
}