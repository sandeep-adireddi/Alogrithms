
/*Insertion-sort 

(a) 5 2 4 6 1 3
(b) 2 5 4 6 1 3
(c) 2 4 5 6 1 3
(d) 2 4 5 6 1 3
(e) 1 2 4 5 6 3
(f) 1 2 3 4 5 6


best case= O(n) when input is already sorted
average case=O(n^2)
worst case= O(n^2) when input is reverse sorted



*/

#include <stdio.h>	
#include <stdlib.h>

int main(){

int arraySize = 0;
scanf("%d",&arraySize);
int *array = (int*) malloc(arraySize * sizeof(int));  // initailzation of array of input size 

for (int i = 0; i < arraySize; ++i)
{
	scanf("%d",array + i);    //storing elements in array

	
}
/* Main Algorithm*/
for (int i = 1; i < arraySize; ++i)
{
	int key = *(array + i);      // choosing an element starting from 2nd element to last element (loop)                 
	int j = i-1;

	while (j >=0 && *(array + j) > key)   // Comparing all the previous elements to key to find an element  greater then key 
	{
		*(array + j + 1)=*(array + j);    //copy the found element on to its next element
		j = j-1;
	}

	*(array + j+1) = key;				// copy the key in place of element which is just less then key
	
}
/* end of Main Algorithm*/
for (int i = 0; i < arraySize; ++i)
{
	printf("%d\n",*(array + i));        // printing the sorted array
	
}
return 0;
}