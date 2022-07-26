/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:51:36 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:51:36 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int a[200005];
int dp[200005];
int n,ans=-2147483646;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    dp[0]=a[0];
    for(int i=0;i<n;i++)
        dp[i]=max(dp[i-1]+a[i],a[i]);
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}
