#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,cnt=1,i,f[1010];
    f[0]=f[1]=1;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
        if(i%2==0)
            f[i]=f[i-1]+f[i/2];
        else
            f[i]=f[i-1];
    printf("%d\n",f[n]);
    return 0;
}