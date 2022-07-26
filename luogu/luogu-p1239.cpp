/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:03:55 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:03:55 
 */
#include <bits/stdc++.h>
using namespace std;
int a[10];
void cal(int x)
{
    while(x) a[x%10]++,x/=10;
}
int main()
{
    int n; 
    scanf("%d",&n);
    if(n<10000) 
        for(int i=1;i<=n;i++)
            cal(i);
    else 
    {
        for(int i=1;i<=9999;i++)
            cal(i);
        for(int i=1;i<=n/10000-1;i++)
        {
            int s=i;
            while(s) a[s%10]+=10000,s/=10;
        }
        for(int i=0;i<=9;i++) a[i]+=4000*(n/10000-1);
        for(int i=n/10000*10000;i<=n;i++) cal(i);
    }
    for(int i=0;i<=9;i++) cout<<a[i]<<endl;
    return 0;
}