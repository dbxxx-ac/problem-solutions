#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ground[10001][4],n,x,y;
    bool have=false;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&ground[i][0],&ground[i][1],&ground[i][2],&ground[i][3]);
        ground[i][2]+=ground[i][0];
        ground[i][3]+=ground[i][1];
    }

    scanf("%d%d",&x,&y);
    for(int i=n;i>=1;i--)
    {
        if(ground[i][0]<=x&&ground[i][1]<=y&&ground[i][2]>=x&&ground[i][3]>=y)
        {
            printf("%d",i);
            have=true;
            break;
        }
    }

    if(!have)
        printf("-1");
    return 0;
}
