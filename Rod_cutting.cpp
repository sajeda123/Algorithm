// A Dynamic Programming solution for Rod cutting problem
#include<iostream>
#include<cstdio>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}
int Rod_Cutting (int price[], int n)
{
   int value[n+1];
   value[0] = 0;
   int i, j;

   //  bottom up  Approach
   for (i = 1; i<=n; i++)
   {
       int max_value = INT_MIN;
       for (j = 0; j < i; j++)
         max_value = max(max_value, price[j] + value[i-j-1]);
       value[i] = max_value;
   }

   return value[n];
}
int main()
{

    int N;
    cin>>N;
    int arr[N];
     for(int i=0;i<N;i++)
        cin>>arr[i];
    cout<<"Maximum Value is="<<Rod_Cutting(arr,N)<<endl;
    return 0;
}

