/*
Time complexity:O(1)
Space complexity:O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void swap(int x1,int x2)
{
    int temp=x1;
    x1=x2;
    x2=temp;
    cout<<"Swapped numbers are "<<x1<<" and  "<<x2<<endl;
}
int main()
{
    int x1,x2;
    cout<<"Enter the first number: ";
    cin>>x1;
    cout<<"Enter the second number: ";
    cin>>x2;
    swap(x1,x2);
    return 0;
}
/*
Time complexity:O(1)
Space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
void swap(int x1,int x2)
{
    x1=x1^x2;
    x2=x1^x2;
    x1=x1^x2;
    cout<<"Swapped numbers are "<<x1<<" and  "<<x2<<endl;
}
int main()
{
    int x1,x2;
    cout<<"Enter the first number: ";
    cin>>x1;
    cout<<"Enter the second number: ";
    cin>>x2;
    swap(x1,x2);
    return 0;
}
*/