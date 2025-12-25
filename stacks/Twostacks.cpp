#include<bits/stdc++.h>
using namespace std;
class TwoStack 
{
	int *arr;
    int top1;
    int top2;
    int size;
    public:
    TwoStack(int s) 
    {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    void push1(int num) 
    {
        if(top2 - top1 > 1 ) 
        {
            top1++;
            arr[top1] = num;
        } 
    }
    void push2(int num)
    {
         if(top2 - top1 > 1 )
        {
            top2--;
            arr[top2] = num;
        }
    }
    int pop1() 
    {
		if( top1 >= 0) 
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2() 
    {
		if( top2 < size) 
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    TwoStack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push2(20);
    s.push2(50);
    s.push2(60);
    cout<<s.pop1()<<endl;
    return 0;
}