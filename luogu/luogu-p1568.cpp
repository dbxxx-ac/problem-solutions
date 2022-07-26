/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:33:52 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:33:52 
 */
#include <bits/stdc++.h>
using namespace std;
int m,n,x,y,a[1000100],b[1000100],timex,ans;
bool stat[1000100];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        for(int j=1;j<=y;j++)
        a[timex+j]=a[timex+j-1]+x;
        timex+=y;
    }
    timex=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        for(int j=1;j<=y;j++)
        b[timex+j]=b[timex+j-1]+x;
        timex+=y;
    }
    for(int i=1;i<=timex;i++)
    {
        if(a[i]>=b[i])
        stat[i]=false;
        if(a[i]<b[i])
        stat[i]=true;
        if(i==1||stat[i-1]!=stat[i])
            ans++;
    }
    printf("%d",ans-1);
    return 0;
}