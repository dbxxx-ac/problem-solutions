#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int w[20000];
int main()
{
    int n,h,i;
    scanf("%d %d",&n,&h);
    for(i=0;i<n;i++) 
        scanf("%d",&w[i]);
    sort(w,w+n);
    for(i=n-1;h>0;i--) 
        h-=w[i];
    printf("%d",n-i-1);
    return 0;
}