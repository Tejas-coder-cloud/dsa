#include<iostream>
using namespace std;

    enum Sorted {ascending,descending,unsorted};
    Sorted checkorder(int a[],int n,int index=0)
    {
        if(index==n-1)
        {
            return ascending;
        }
        Sorted result= checkorder(a,n,index+1);
        if(a[index]>a[index+1])
        {
            if(result==ascending)
            {
                 return unsorted;
            }
            return descending;
           
        }
         else  if(a[index]<a[index+1])
        {
            if(result==descending)
            {
                  return unsorted;
            }
            return ascending;
        }
        else
        {
            return result;

        }
    }
int main()
{
    int a[]={5,6,2,1,4},n=sizeof(a)/sizeof(a[0]);
    Sorted result1=checkorder(a,n);
     switch (result1) {
        case ascending:
            cout << "Array is sorted in ascending order.\n";
            break;
        case descending:
            cout << "Array is sorted in descending order.\n";
            break;
        case unsorted:
            cout << "Array is not sorted.\n";
            break;
    }
    return 0;
}