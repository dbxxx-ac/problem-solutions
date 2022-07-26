/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:44:54 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:44:54 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,t,ans,l,r,b[1050];
bool a[1050];
int main()
{
    scanf("%d%d",&m,&n);
    while(n--)
    {
        scanf("%d",&t);
        if(!a[t]) 
        {
            ans++;
            r++;b[r]=t;a[t]=1;
            if(r>m)
            {
                l++;
                a[b[l]]=0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
