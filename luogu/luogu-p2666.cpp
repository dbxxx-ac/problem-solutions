/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:01:57 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:01:57 
 */
#include <bits/stdc++.h>
using namespace std;
int num[105];
bool vis[20005];
int n,ans,x;
int main()
{
    cin>>n;
    x=sqrt(n);
    for(int i=0;i<=x;i++)
    {
        num[i]=i*i;
        vis[i*i]=true;
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(num[i]+num[j]>n) break;
            for(int k=0;k<=x;k++)
            {
                if(num[i]+num[j]+num[k]>n) break;
                if(vis[n-num[i]-num[j]-num[k]]) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}