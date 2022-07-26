#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int l,m,h,t,ans=0;
    int a[10001];
    cin>>l>>m;
    for (int i=0;i<=l;i++)
        a[i]=1;
    for (int i=1;i<=m;i++)
    {
        cin>>h>>t;
        for (int j=h;j<=t;j++)
            a[j]=0;
    }
    for(int i=0;i<=l;i++)
        if(a[i]==1) ans++;
    cout<<ans<<endl;
    return 0;
}