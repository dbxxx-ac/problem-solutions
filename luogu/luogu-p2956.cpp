#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,i,x1,x2,y1,y2,i1,j1,s;
bool b[245][245];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i1=x1;i1<=x2;i1++)
            for(j1=y1;j1<=y2;j1++)
                if(!b[i1][j1])
                {
                    s++;
                    b[i1][j1]=1;
                }
    }
    printf("%d\n",s);
}