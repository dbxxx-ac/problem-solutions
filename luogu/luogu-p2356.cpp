/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:37:03 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:37:03 
 */
#include <bits/stdc++.h>
using namespace std;
int ans=-1,n,a[1005][1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==0) 
            {
                int s=0;
                for(int k=1;k<=n;k++)
                    s+=a[i][k]+a[k][j];
                ans=max(ans,s);
            }
    ans==-1?cout<<"Bad Game!":cout<<ans;
    return 0;
}