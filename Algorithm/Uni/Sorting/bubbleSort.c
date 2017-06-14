#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int* arr , int n);
int main()
{
	
	
   int n;
	scanf("%d",&n);
	
   int arr[n];
   
   int i;
   for( i = 0 ; i < n ; i++)
   {
   		scanf("%d",&arr[i]);
   }
   

   printf("%d", bubbleSort( arr , n ) );
   /*
   int* test = selectionSort( arr , n );
   
   for(i = 0 ; i < n ; i++)
   {
   	printf("%d ",test[i]);
   }*/
 
    
}


int bubbleSort(int* arr , int n)
{
	int times = 0;
	int tmp;
	
	int last;
	int i;
	for( last = n ; last > 2 ; last--)
	{	
		for( i = 0 ; i < last-1 ; i++)
		{
			if(arr[i] > arr[i+1] )
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				
				times++;
			}
		}	
	}
	
	
	return times;
}
