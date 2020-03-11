#include <iostream>
#include <cstdio>
using namespace std;
int size = 8;
int large_in_two(int array[],int parent,int left)
{
    if(array[parent]>array[left])
        return parent;
    return left;
}
int large_in_three(int array[],int parent,int left,int right)
{
    if(array[parent]>array[left] && array[parent]>array[right])
        return parent;
    else
    {
        if(array[left]>array[right])
            return left;
        else
            return right;
    }
}
int show(int array[],int size)
{
    int i;
    for(i=1; i<=size; i++)
        printf("%d ",array[i]);
}

int heapify(int array[],int pindex)
{
    int largest=pindex;
    int leftchild=pindex*2;
    int rightchild=pindex*2 +1;
//some parent has left child some has left and right child
//we have to find the largest element
//test if the current parent has one or two child
    if(rightchild<=size)
    {
        largest=large_in_three(array,pindex,leftchild,rightchild);
    }
    else
    {
        largest = large_in_two(array,pindex,leftchild);
    }
//if parent is >= child we need not swap
    if(pindex!=largest && largest<=size)
    {
        swap(array[pindex],array[largest]);
        heapify(array,largest);
    }
}
int heapsort(int array[],int sizetocall)
{
    int i,pindex;
    for(i=1; i<=sizetocall; i++)
    {
//we will call heapify 7 times
//we will get the parent size/2
        pindex = size/2;
//now we need to loop from last parent to the first parent
        while(pindex>=1)
        {
            heapify(array,pindex);
            pindex--;
        }
//now we will get the largest element
//swap it with the last element
        swap(array[1],array[size]);
//as last element already sorted so we need to reduce size
        size--;
    }
}

int main()
{
    int size_to_call_heap=size;
    int ar[]= {2,4,15,7,6,3,11,5};

//unsorted array
    show(ar,8);
    printf("\n");

//call heap
    heapsort(ar,size_to_call_heap);
    show(ar,8);

    return 0;
}

