#include<vector>
#include<iostream>
using namespace std;

    pair<int, int> findFloorCeil(const vector<int>& arr, int k) {
        int start=0;
        int end=arr.size()-1;
        int floor=-1,ceil=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
             if (arr[mid]==k)
             {
                 floor=arr[mid];
                 ceil=arr[mid];
                 return {floor,ceil};
             }
             else if(arr[mid]<k)
             { 
                 floor=arr[mid];
                 start =mid+1;
             }
             else
             {
                 end=mid-1;
             }
         }
         start =0, end=arr.size()-1;
         while(start<=end)
         {
             int mid=start+(end-start)/2;
             if(arr[mid]>=k)
             {
                 ceil=arr[mid];
                 end=mid-1;
             }
             else
             {
                 start=mid+1;
             }
             
         }
           return {floor,ceil};
    }
    int main()
    {
        vector<int> a={2,3,4,5,6};
        int k=3;
        pair<int,int> x=findFloorCeil(a,k);
        cout<<"floor is "<<x.first<<" "<<"ceil is "<<x.second;
        return 0;
    }
