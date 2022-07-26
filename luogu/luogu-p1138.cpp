#include <iostream>
#include <set>
using namespace std;
set<int> t;
int main()
{
    int n,k;
    cin>>n>>k;
    while(n--)
    {
        int a;
        cin>>a;
        t.insert(a);
    }
    if(k>t.size()||k<=0)
    {
        cout<<"NO RESULT"<<endl;
        return 0;
    }
    for(int i=1;i<k;i++)
        t.erase(t.begin());
    cout<<*t.begin()<<endl;
}
