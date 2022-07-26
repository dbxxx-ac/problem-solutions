/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:40:22 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:40:22 
 */
#include <iostream>
#include <cstdio>
using namespace std;
struct food
{
    int v;//volume
    int w;//weight
    int c;//calorie
}a[55];
int max(int a,int b)
{
    return a>b?a:b;
}
long long dp[505][505];
int v,w,n;
int main()
{
    scanf("%d%d%d",&v,&w,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].v,&a[i].w,&a[i].c);
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i].v;j--)
            for(int l=w;l>=a[i].w;l--)
                dp[j][l]=max(dp[j][l],dp[j-a[i].v][l-a[i].w]+a[i].c);
    printf("%d\n",dp[v][w]);
    return 0;
}
