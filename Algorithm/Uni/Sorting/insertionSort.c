#include <stdio.h>
#include <stdlib.h>

int insertionSort(int* arr , int n);
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
   

   printf("%d", insertionSort( arr , n ) );
   /*
   int* test = insertionSort( arr , n );
   
   for(i = 0 ; i < n ; i++)
   {
   	printf("%d ",test[i]);
   }*/
    
}

int insertionSort(int* arr , int n)
{
	int times = 0;
	int loc;
	int newItem;
	
	int i;
	for( i = 1 ; i < n ; i++)
	{
		loc = i-1;
		newItem = arr[i];
		
		while(i>=1 && newItem<arr[loc])
		{
			arr[loc+1] = arr[loc];
			loc--;
			
			times++;
		}
		arr[loc+1] = newItem;
		times++;
	}
	
	return times;
}
