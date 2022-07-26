/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:35:21 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:35:21 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int city[10001][4],n,x,y,m,s,ansx;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&city[i][0],&city[i][1],&city[i][2],&city[i][3]);

    while(m--)
    {
        scanf("%d%d",&x,&y);
        for(int i=1;i<=n;i++)
            if(city[i][0]<=x&&city[i][1]<=y&&city[i][2]>=x&&city[i][3]>=y)
                s=i,ansx++;
        if(ansx) cout<<"YES"<<' '<<ansx<<' '<<s<<endl;
        else    printf("NO\n");
        ansx=0;
    }
    return 0;
}
