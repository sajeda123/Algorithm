#include<iostream>
using namespace std;

void counting_sort(int arr[],int n){
    int i,j;
    int temp[10]={0};
    int count1[10]={0};
    for(i=0;i<n;i++){
        count1[arr[i]]++;
    }

     for(i=1;i<10;i++){
        count1[i]=count1[i-1]+count1[i];
    }

    for(i=n-1;i>=0;i--){
        temp[count1[arr[i] ] ]=arr[i];
         count1[arr[i]]--;
    }
    for(i=0,j=0;i<10;i++){
        if(temp[i]>0){
            arr[j]=temp[i];
            j++;
        }
    }

}
int main()
{
    int arr[]={5,2,9,5,2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
