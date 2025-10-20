#include<iostream>
using namespace std;
int linear_search(int k,int n,int a[],int index=0)
{
    if(index>=n)
    {
        return -1;
    }
    if(a[index]==k)
    {
        return index;
    }
    return linear_search(k,n,a,index+1);
}
int main()
{
    int a[]={2,3,4,5,6},k,n=sizeof(a)/sizeof(a[0]);
    cout<<"Enter the number to search in the array";
    cin>>k;
    int result=linear_search(k,n,a);
    if(result!=-1)
    {
        cout<<"Target element found at "<<"index"<<" "<<result;

    }
    else
    {
        cout<<"Number not found";
    }
    return 0;
    // time complexity:O(n)
    // space complexity:O(n)

}