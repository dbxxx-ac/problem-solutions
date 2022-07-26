/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:57:26 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:57:26 
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,sum,ans=INT_MAX,pain[3005];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pain[i]);
        if(i<m-1) sum+=pain[i];
        else 
        {
            ans=min(sum+pain[i]-pain[i-m],ans);
            sum+=pain[i]-pain[i-m];
        }
    }
    if(n==0) ans=0;
    cout<<ans<<endl;
}