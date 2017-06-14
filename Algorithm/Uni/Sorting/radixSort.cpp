#include <iostream>
#include <queue>

using namespace std;

void radixSort(int arr[], int n, int k);
int digit(int arr_n , int digit);

int main()
{
    int n,k;

	cin>>n;
	cin>>k;


//	cout<< digit(n,k);


  	int arr[n+1];
	arr[0] = 0;

	int i;
	for( i = 1 ; i <= n ; i++)
	{
	  	cin>>arr[i];
	}

	radixSort( arr , n , k);

	for( i = 1 ; i <= n;i++)
	{
		cout<<arr[i]<<" ";
	}



}



void radixSort(int arr[], int n, int k)
{
   //원소들이 각각 최대 k 자리수인 A[1..n]을 정렬한다.
	 //가장 낮은 자리수를 1번째 자리수라 함
   queue<int> que[10];


   int d;
   int p;

   for(int i = 1 ; i <= k ; i++)
   {
   		for(int j = 1 ; j <= n ; j++)
   		{
   			d = digit(arr[j],i);
   			que[d].push(arr[j]);
		}
		p = 1;
		for(int j = 0 ; j <= 9 ; j++)
		{
			while( !que[j].empty() )
			{
				arr[p++] = que[j].front();
				que[j].pop();
			}
		}
   }


}

int digit(int arr_n , int digit)
{
	int num=1;
	if(digit != 1)
	{
		for(int i = 0 ; i < digit ; i++)
			num*=10;
	}
	else
	{
		return arr_n % 10;
	}


	return (arr_n- (arr_n / num)*num)/(num/10);
}
