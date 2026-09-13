/*
Time complexity: O(logn)
Space complexity: O(n)
right neighbour=2*i+1
left neighbour=2*i
parent =i/2
*/
#include<bits/stdc++.h>
using namespace std;
class Heap
{
    public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {
        size+=1;
        int index=size;
        arr[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else 
            {
                return;
            }
        }
    }
    void deleteFromMaxHeap()
    {
        if(size==0)
        {
            cout<<"Nothing to delete "<<endl;
            return;
        }
        // Step 1 : Put last element into first position
        arr[1]=arr[size];
        // Step 2: Remove last element
        size--;
        // Step 3: Take root node to its correct position
        int i=1;
        while(i<size)
        {
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex])
            {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex])
            {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        cout<<" The elements of heap are as follows: ";
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    Heap h;
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(10);
    h.insert(67);
    h.print();
    h.deleteFromMaxHeap();
    h.print();
    return 0;
}