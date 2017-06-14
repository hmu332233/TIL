#include <stdio.h>
#include <stdlib.h>

void buildHeap(int* arr,int n);
void heapify(int* arr , int k, int n);

int times = 0;
int sw = 0;

int main()
{


    int n;

	scanf("%d",&n);

   int arr[n+1];
   arr[0] = 0;

   int i;
   for( i = 1 ; i <= n ; i++)
   {
   		scanf("%d",&arr[i]);
   }

 	heapSort( arr , n );

 	for( i = 1 ; i <= n;i++)
   {
   		printf("%d ",arr[i]);
   }


 	printf("%d" , times);

}

void heapSort(int* arr , int n)
{
	int tmp;

	buildHeap(arr,n);

	sw = 1;

	int i;
	for( i = n ; i >= 2 ; i--)
	{
		tmp = arr[i];
		arr[i] = arr[1];
		arr[1] = tmp;

		heapify(arr,1,i-1);
	}

}

void buildHeap(int* arr,int n)
{
	int i; //각 부모노드
	for( i = n/2 ; i >= 1 ; i--)
	{
		heapify(arr,i,n);
	}
}

void heapify(int* arr , int k, int n)
{
	int bigger;

	int left = 2*k;
	int right = 2*k+1;

	if(right <= n)
	{
		if(arr[left] > arr[right] ) bigger = left;
		else bigger = right;
	}
	else if (left <= n)
		bigger = left;
	else return;

	int tmp;

	//자식이 더 크면 위로 올림
	if( arr[bigger] > arr[k] )
	{
		tmp = arr[bigger];
		arr[bigger] = arr[k];
		arr[k] = tmp;

		heapify(arr,bigger,n);

		if( sw == 1)
			times++;
	}

}
