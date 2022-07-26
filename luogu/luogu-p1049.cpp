/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:28:56 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:28:56 
 */
#include <iostream>
#include <cstdio>
#undef max
using namespace std;
int v,n,a[35],dp[30005];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    printf("%d\n",v-dp[v]);
    return 0;
}