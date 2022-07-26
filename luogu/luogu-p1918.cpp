#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map<int,int> bowling;
int main()
{
    int n,k,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        bowling[x]=i;
    }
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&x);
        printf("%d\n",bowling[x]>0?bowling[x]:0);
    }
}
