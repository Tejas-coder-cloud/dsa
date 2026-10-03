#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string number)
{
    int p2=1,num=0;
    for(int i=number.size()-1;i>=0;i--)
    {
        if(number[i]%2==1)
        {
            num=num+p2;
        }
        p2=p2*2;
    }
    return num;
}
int main()
{
    string n;
    cout<<"Enter a binary number: ";
    cin>>n;
    cout<<"The decimal equivalent is: "<<binaryToDecimal(n)<<endl;
    return 0;
}