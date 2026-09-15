#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Creation
    unordered_map<string,int> mp;
    // Insertion 
    pair<string,int> pair1=make_pair("Tejas",1);
    mp.insert(pair1);
    pair<string,int> pair2("Nayan",2);
    mp.insert(pair2);
    mp["Heet"]=3;
    // Searching
    cout<<"The frequency of Tejas is: "<<mp["Tejas"]<<endl;
    cout<<"The frequency of Nayan is: "<<mp.at("Nayan")<<endl;
    // Size
    cout<<"The size of the map is: "<<mp.size()<<endl;
    // Count
    cout<<"The key is present "<<mp.count("Bro")<<endl;
    // erase
    mp.erase("Heet");
    cout<<"The size of the map after erasing an element "<<mp.size()<<endl;
    // Traversal
    for(auto i:mp)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    unordered_map<string,int> :: iterator it=mp.begin();
    while(it!=mp.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }




    
    return 0;
}