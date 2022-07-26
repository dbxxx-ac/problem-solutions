#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i,j,n,m,s=0,k=-1;
    scanf("%d",&n);
    s=n*n;
    j=n;
    while(s)
    {
        scanf("%d",&m);
        s-=m;
        k++;
        for(i=1;i<=m;i++)
        {
            j--;
            printf("%d",k%2);
            if(!j)
                printf("\n"),j=n;
        }
    }
    return 0;
}