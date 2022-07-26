/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:06:38 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:06:38 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,m,n,t;
    scanf("%d",&k);
    for(m=n=1;m+n<=k;)
    {
        t=m+n;
        m=n;
        n=t;
    }
    printf("m=%d\n",m);
    printf("n=%d\n",n);
    return 0;
}