#include <stdio.h>
#include<stdlib.h>
int findMax(int a,int b)
{
	if (a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int max(int a,int b,int c)
{
	return findMax(findMax(a,b),c);
}

int maxCrossSubarraySum(int *array,int start,int middle,int end)
{
	int sum  = 0;
	int leftSum = -100000;;
	int rightSum = -1000000;

	for (int i = middle; i >=start; --i)             //finding the max left sum
	{
		sum = sum + *(array+i);
		if (sum >= temp)
		{
			temp = sum;
			leftSum = temp;
		}
		
	}
	sum = 0;
	for (int i = middle+1; i <= end; ++i)            // finding the max right sum
	{
		sum = sum + *(array+i);
		if (sum >= temp)
		{
			temp = sum;
			rightSum = sum;
			
		}
		
	}

	return leftSum+rightSum;
}


int maximumSubArray(int *array,int start,int end)
{

if(start == end)

{
	return *(array+end);  //base codition return the element if there is onlt one element
}

else

{
	int middle = (start + end)/2;
	return max(maximumSubArray(array,start,middle),maximumSubArray(array,middle+1,end),maxCrossSubarraySum(array,start,middle,end));

	//find t max between left subarray max right subarray max and max of both left and right combine
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

printf("%d\n",  maximumSubArray(array,0,arraySize-1));

return 0;
} 

