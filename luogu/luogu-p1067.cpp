#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,a[105];
int main()
{
    scanf("%d",&n);
    for(int i=n;i>=0;i--)
      scanf("%d",&a[i]);
    bool flag=true;
    for(int i=n;i>=0;i--)
    {
        if(a[i]==0) continue;
        if(!flag&&a[i]>0) printf("+");
        if(a[i]<0) printf("-");
        if(abs(a[i])!=1||i==0) printf("%d",abs(a[i]));
        if(i==0) continue;
        printf("x");
        if(i==1) continue;
        printf("^%d",i);
        flag=false;
    }
    if(flag==true) printf("0");
    return 0;
}