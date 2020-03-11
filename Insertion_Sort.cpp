#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n)
{
    int i,j,temp;
    for(i=1; i<n; i++)
    {
         j=i-1;
        temp=arr[i];
        while(j>=0){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1]=temp;
    }

}
void printArray(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]= {12, 11, 13, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    printArray(arr,n);
    //cout<<"n="<<n<<endl;
}
