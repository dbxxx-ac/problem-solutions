#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1],dp[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxn=0;
    for(int i=n;i>0;i--)
    {
        if(i==n)
            dp[i]=1;
        else if(a[i+1]-1==a[i])
             dp[i]=dp[i+1]+1;
        else
            dp[i]=1;
        maxn=max(dp[i],maxn);
    }
    cout<<maxn;
    return 0;
} 