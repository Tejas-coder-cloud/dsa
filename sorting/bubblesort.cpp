#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
     bool swapped;
    for(int i=1;i<n;i++)
    {
         swapped=false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        
       if(!swapped)
       {
        break;
       } 
    }
    
}
int main()
{
    int arr[]={4,1,0,6,2},n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for(auto i:arr)
    {
        cout<<i;
    }

    return 0;    
}