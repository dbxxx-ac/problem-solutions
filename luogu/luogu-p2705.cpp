#include <iostream>
#include <cstdio>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int r,b,c,d,e;
    scanf("%d%d%d%d%d",&r,&b,&c,&d,&e);
    int ans=0;
    ans+=r*c+b*d;
    if(2*e>c+d)
    {
        int chg=min(r,b);
        ans+=chg*(2*e-c-d);
    } 
    printf("%d\n", ans);
    return 0;
}