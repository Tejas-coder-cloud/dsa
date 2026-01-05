#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> a;
    a.push(10);
    cout<<a.front()<<endl;
    a.push(20);
    a.push(30);
    cout<<"size of the queue is: "<<a.size()<<endl;
    a.pop();
    cout<<"size of the queue is: "<<a.size()<<endl;
    if(a.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        cout<<"queue is not empty"<<endl;
    }    
    return 0;
    
}