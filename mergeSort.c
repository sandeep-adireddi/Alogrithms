
/*MergeSort

Divide And Conqure basied algorithm


best case= O(nlogn)
average case=O(nlogn)
worst case= O(nlogn) 



equation t(n)=2t(n/2) + O(nlogn)

*/

#include <stdio.h>	
#include <stdlib.h>
void Merge(int *array, int start,int middle,int end)
{

int n1 = middle-start+1; //n1 is no of elements in 1st half
int n2 = end-middle;    // n2 is no of elements in 2nd half
int *left  = (int*)malloc((n1+1)*sizeof(int));    // creation of left and right arrays
int *right = (int*)malloc((n2+1)*sizeof(int));

for (int i = 0; i < n1; ++i)
{	
	*(left+i)=*(array+start+i);      // filling left with 1st half of given array
	
}

*(left + (n1)) = 100000;

for (int i = 0; i < n2; ++i)
{
	*(right + i) = *(array+i+middle+1);  //filling right with 2nd half of array
	
}
*(right + (n2)) = 1000000;

int leftIndex = 0;
int rightIndex = 0;
for (int i = start; i <= end; ++i)                  //copying the least element of two arrays into main array one by one to sort 
{ 
	if(*(left+leftIndex) <= *(right+rightIndex))
	{
		*(array+i) = *(left+leftIndex);
		leftIndex++;
	}
	else
	{
		*(array+i) = *(right+rightIndex);
		rightIndex++;
	}

	
}

}
void MergeSort(int *array,int start,int end) 
{
	if (start<end)
	{
		int middle = (start+end)/2;
		printf("%d\n",middle );
		MergeSort(array,start,middle); 	//calling recurseion for first half of array
		MergeSort(array,middle+1,end); //calling recurseion for second half of array
		Merge(array,start,middle,end); // main conqure function
	}
}

int main(){

int arraySize = 0;
scanf("%d",&arraySize);
int *array = (int*) malloc(arraySize * sizeof(int));  // initailzation of array of input size 

for (int i = 0; i < arraySize; ++i)
{
	scanf("%d",array + i);    //storing elements in array

	
}

MergeSort(array,0,arraySize-1); //calling mergesort

for (int i = 0; i < arraySize; ++i)
{
	printf("%d\n",*(array + i));        // printing the sorted array
	
}
return 0;
}