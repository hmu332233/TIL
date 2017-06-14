#include <stdio.h>
#include <stdlib.h>

int* mergeSort(int* arr , int p, int r, int* times);
//int* merge(int* arr, int p , int q, int r);
int* merge(int* arr, int p , int q, int r, int* times);

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
   
   int* test = mergeSort( arr , 0 ,n-1 , &times );
   
   for(i = 0 ; i < n ; i++)
   {
   	printf("%d ",test[i]);
   }
   
  
 	printf("%d" , times);
  
}


int* mergeSort(int* arr , int p, int r, int* times )
{
	if( p < r )
	{
		int q= (p+r)/2;
		
		arr = mergeSort(arr,p,q, times);	
		arr = mergeSort(arr,q+1,r, times);
		//arr = merge(arr,p,q,r);
		arr = merge(arr,p,q,r,times);
	}
	
	return arr;
}

int* merge(int* arr, int p , int q, int r, int* times)
{
	int tmp[r+1];
	
	int i = p;
	int j = q+1;
	int t = 0;
	
	while(i <= q && j <= r)
	{
		if( arr[i] <= arr[j] )
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
			
			
		(*times)++;
	}
	
	while(i <= q)
		tmp[t++] = arr[i++];
		
	while(j <= r)
		tmp[t++] = arr[j++];
		
	
	i = p;
	t = 0;
	
	while(i <= r)
		arr[i++] = tmp[t++];
	
	
	return arr;
}
