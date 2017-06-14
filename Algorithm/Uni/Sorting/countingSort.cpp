#include <iostream>
#include <queue>

using namespace std;

void countingSort(int* A, int* B, int n);

int main()
{

    int n;

	cin>>n;

  	int arr[n+1];
	arr[0] = 0;

	int i;
	for( i = 1 ; i <= n ; i++)
	{
	  	cin>>arr[i];
	}

	int B[n+1];
	B[0] = 0;
	countingSort( arr , B , n);



}



void countingSort(int A[], int B[], int n)
{

   int max = A[1];
   int min = A[1];

   for(int i = 1 ; i <= n ; i++)
   {
   		if( max < A[i] ) max = A[i];
   		if( min > A[i] ) min = A[i];
   }

   int k;

   k = max - min + 1;

  //카운트배열
	int count[k];
   //횟수 초기화
   for(int i = 0 ; i < k ; i++)
   {
   		count[i] = 0;
   }
   //숫자세기
    for(int j = 1 ; j <= n ; j++)
    {
    	count[A[j]-min]++;
	}


    for(int i = 1 ; i < k ; i++)
    {
    	count[i] += count[i-1];
	}

	//출력 --------------------------
	for( int i = 0 ; i < k ; i++)
		cout<<count[i]<<" ";

	cout<<endl;
	//-------------------------



	for( int j = n ; j >= 1 ; j-- )
	{
		B[count[A[j]-min]] = A[j];
     	count[A[j]-min]--;
	}

//--------------------------




	for(int i = 1 ; i <= n ; i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;

}
