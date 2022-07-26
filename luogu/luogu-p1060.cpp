/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:41:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 21:41:29
 * 
 * 由p1048魔改
 */
#include <iostream>
#include <cstdio>
struct MEDICINE
{
    int t;
    int v;
}a[105];
int t,n;
int dp[40][30005];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%d%d",&t,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].t,&a[i].v);
        a[i].v*=a[i].t;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=t;j++)
            dp[i][j]=max(j>=a[i].t?(dp[i-1][j-a[i].t]+a[i].v):0,dp[i-1][j]);
    printf("%d\n",dp[n][t]);
    return 0;
}
