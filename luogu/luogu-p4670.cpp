/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:03:30 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:03:30 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
long long s,l=1,size[100001];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&size[i]);
    sort(size+1,size+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=l+1;j<=n;j++)
            if(size[i]*0.9<=size[j]) l=j;
            else break;
        s+=l-i;
    }
    printf("%lld",s);
}