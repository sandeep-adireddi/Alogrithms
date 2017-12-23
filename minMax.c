/*

Finding minmax is 3*(n-1)/2 comparisions

*/

#include <stdio.h>
#include <stdlib.h>

struct minMax
{
	int min ;
	int max ;
};

int main()
{	

	int arraySize = 0;
	int i = 0;
	struct minMax pair;
	scanf("%d",&arraySize);
	int *array = (int*) malloc(arraySize * sizeof(int));  // initailzation of array of input size 

	for (int i = 0; i < arraySize; ++i)
	{
		scanf("%d",array + i);    //storing elements in array

		
	}
	if (arraySize%2 == 0)		//initialize the first two elements as minimum and maximum  if arraysize is even
	{    i = 2;
		if (*(array) <= *(array + 1))
		{
			pair.min = *(array);
			pair.max = *(array+1);
		}
		else
		{
			pair.max = *(array);
			pair.min = *(array+1);
		}
	}
	else 						/*initialize the first element as minimum and maximum if arraysize is odd*/
		{
			pair.min = *(array);
			pair.max = *(array);
			i = 1;
	}
	for (; i < arraySize;)                   /* In the  loop, pick elements in pair and   compare the pair with max and min so far */   

	{
		if (*(array+i) > *(array+i+1) )         
    {
      if(*(array+i) > pair.max)        
       {  
       	pair.max =*(array+i);
       }

      if(array[i+1] <  pair.min)          
       { 
        pair.min = array[i+1];
    }

    }

    else        
    {
      if (array[i+1] >  pair.max)        
      {
         pair.max = array[i+1];
      }
      if (*(array+i) < pair.min)          
      {  
       pair.min = *(array+i);
      }
    }
      i=i+2;    
    }        
 
	printf("%d %d \n", pair.min,pair.max );	
	return 0;
}