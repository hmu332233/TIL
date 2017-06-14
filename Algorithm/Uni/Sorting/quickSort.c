#include <stdio.h>
#include <stdlib.h>

int quickSort(int* arr , int p, int r,int* times);
int partition(int* arr, int p, int r, int* times );

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
   int times = 0;

   printf("%d", quickSort(arr,0,n-1, &times) );
   /*
 	for( i = 0 ; i < n ;i++)
   {
   		printf("%d ",arr[i]);
   }
    */

}


int quickSort(int* arr , int p, int r, int* times )
{
	int q;

	if( p < r )
	{
		q = partition(arr, p , r, times );
		*times += quickSort(arr,p,q-1, times);
		*times += quickSort(arr,q+1,r, times );
	}


	return *times;
}

int partition(int* arr, int p, int r, int* times )
{
	int tmp;

	int criterion = arr[r]; //기준원소
	int i = p-1; //왼쪽시작점
	int j;	//오른쪽시작점


	//작으면 왼쪽 크면 오른쪽 
	for( j = p ; j <= r-1 ; j++ )
	{
		if(arr[j] < criterion )
		{
			tmp = arr[++i];
			arr[i] = arr[j];
			arr[j] = tmp;

			(*times)++;
		}
	}

	int q = i+1;

	tmp = arr[q];
	arr[q] = arr[r];
	arr[r] = tmp;
	(*times)++;

	return q;
}
