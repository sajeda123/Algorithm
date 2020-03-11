#include<bits/stdc++.h>
using namespace std;
int maximum_subarray_sum(int arr[],int n)
{
    int max_so_far=0;
    int max_ending_here=0;
    for(int i=0; i<n; i++)
    {
        max_ending_here=max_ending_here+arr[i];
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
        }
    }
    return max_so_far;
}

int main()
{
    int arr[100]= {-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_sum=maximum_subarray_sum(arr,n);
    cout<<"Maximum contiguous sum is="<<max_sum<<endl;
    return 0;
}
