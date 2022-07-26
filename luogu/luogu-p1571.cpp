#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map<int,int> science;
int main()
{
    int n,m,a[100005],b[100005];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        science[a[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        science[b[i]]++;
    }
    for(int i=0;i<n;i++)
        if(science[a[i]]==2)
            printf("%d ",a[i]);
    return 0;
}
