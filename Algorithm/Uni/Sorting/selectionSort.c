#include <stdio.h>
#include <stdlib.h>

int theLargest(int* arr , int last , int* times);
int selectionSort(int* arr , int n );

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


   printf("%d", selectionSort( arr , n ) );
   /*
   int* test = selectionSort( arr , n );

   for(i = 0 ; i < n ; i++)
   {
   	printf("%d ",test[i]);
   }*/


}

int selectionSort(int* arr , int n )
{
	int k;
	int tmp;
	int times = 0;

	int last;
	for( last = n-1 ; last >= 1 ; last-- )
	{
		k = theLargest( arr , last , &times );

		tmp = arr[k];
		arr[k] = arr[last];
		arr[last] = tmp;
	}

	return times;
}

int theLargest(int* arr , int last , int* times)
{
	int largest = 0;

	int i;
	for( i = 0 ; i <= last ; i++)
	{
		if(arr[i] > arr[largest])
		{
			largest = i;
			(*times)++;
		}

	}

	return largest;
}
