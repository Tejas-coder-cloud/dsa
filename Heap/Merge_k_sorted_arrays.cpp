#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data,row,column;
    Node(int data,int row , int column)
    {
        this->data=data;
        this->row=row;
        this->column=column;
    }
};
class compare
{
    public:
    bool operator()(Node *a, Node *b)
    {
        return a->data>b->data;
    }
};
vector<int> merge_k_sorted_arrays(vector<vector<int>> & arr, int k)
{
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        Node* temp=new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    while(!minHeap.empty())
    {
        Node* temp=minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int row=temp->row;
        int column=temp->column;
        if(column+1<arr.size())
        {
            Node* next=new Node(arr[row][column+1],row,column+1);
            minHeap.push(next);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr=
    {
        {1,2,3},
        {0,4,5},
        {7,8,9}
    }; int k=3;
    vector<int> ans=merge_k_sorted_arrays(arr,k);
    cout<<"The single sorted array is: ";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}