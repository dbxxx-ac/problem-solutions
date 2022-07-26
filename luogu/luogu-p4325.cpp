#include <iostream>
#include <cstdio>
using namespace std;
int ans,a[42],x;
int main()
{
    for (int i=1;i<=10;i++)
    {
        scanf("%d",&x);
        a[x%42]=1;
    }
    for (int i=0;i<42;i++)
        if(a[i])
            ans++; 
    printf("%d",ans);
    return 0;
}