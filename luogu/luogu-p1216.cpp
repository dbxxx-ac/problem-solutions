/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:43:50 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:43:50 
 */
#include <iostream>
#include <cstdio>
int dp[1005][1005];
int a[1005][1005];
int n;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    for(int i=n;i>0;i--)
        dp[n][i]=a[n][i];
    for(int i=n-1;i>0;i--)
        for(int j=i;j>0;j--)
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
    printf("%d\n",dp[1][1]);
    return 0;
}
