#include <bits/stdc++.h>
using namespace std;
string maxans,president[24];
int maxnum,n;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>president[i];
        if(president[i].size()>maxans.size()||(president[i].size()==maxans.size()&&president[i]>maxans))
        {
            maxans=president[i];
            maxnum=i+1;
        }
    }
    cout<<maxnum<<endl<<maxans;
    return 0;
}
