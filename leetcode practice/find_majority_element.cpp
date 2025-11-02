#include<bits/stdc++.h>
using namespace std;
int majority_element(vector<int> & a)
{
    sort(a.begin(),a.end());
    int n=a.size();
    int start=0,end=n;
    int mid=start+(end-start)/2;
    return a[mid];
}
int main()
{
    vector<int> arr={1,1,1,2,3,3,4,4,4,4,4,4};
    int ans=majority_element(arr);
    cout<<"The majority element is "<<ans<<endl;
    return 0;
}
// assumption:  majority element always exist 