#include <bits/stdc++.h>
using namespace std;
struct node 
{
    int dir;
    string name;
}people[100005];
int n,m,x,y;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>people[i].dir>>people[i].name;
    int now=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(!((people[now].dir+x)%2)) now=(now+n-y)%n;
        else if((people[now].dir+x)%2) now=(now+y)%n;
    }
    cout<<people[now].name<<endl;
    return 0;
}