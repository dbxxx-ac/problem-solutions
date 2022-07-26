#include <iostream>
using namespace std;
int t[200005],g[200005];
int n,a[105],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[a[i]]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            t[a[i]+a[j]]++;
    for(int i=1;i<=200002;i++)
        if(t[i]>0&&g[i]) 
            ans++;
    cout<<ans;
    return 0;
}