#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> t;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        t.insert(a);
    }
    cout<<t.size()<<endl;
    while(!t.empty())
    {
        cout<<*t.begin()<<" ";
        t.erase(t.begin());
    }
    return 0;
}
