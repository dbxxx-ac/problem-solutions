/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:56:11 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:56:11 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int ax,ay,bx,by,n,step;
char dir;
int main()
{
    scanf("%d%d%d%d%d",&ax,&ay,&bx,&by,&n);

    while(n--)
    {
        cin>>dir;
        if(ax==bx&&ay==by)
        {
            printf("%d\n",step);
            return 0;
        }
        if(ax>bx&&dir=='S') ax--,step++;
        if(ax<bx&&dir=='N') ax++,step++;
        if(ay>by&&dir=='W') ay--,step++;
        if(ay<by&&dir=='E') ay++,step++;
    }
    printf("-1\n");
    return 0;
}
