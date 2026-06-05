#include<bits/stdc++.h>
using namespace std;
int maxsum(int arr[],int k,int n)
{
    int leftsum=0,maxsum=0,rightsum=0;
   for(int i=0;i<k;i++)
   {
    leftsum=leftsum+arr[i];
   }
   maxsum=leftsum;
   int rightindex=n-1;
   for(int i=k-1;i>=0;i--)
   {
    leftsum=leftsum-arr[i];
    rightsum=rightsum+arr[rightindex];
    rightindex-=1;
    maxsum=max(maxsum,rightsum+leftsum);
   }
   
   return maxsum;
}
int main()
{
    int arr[]={1,2,3,4,5},k=4;
    int answer =maxsum(arr,k,5);
    cout<<"The maximum sum for the "<<k<<" elements is "<<answer;
    return 0;
}