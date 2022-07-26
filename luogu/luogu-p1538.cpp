/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:52 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:52 
 */
#include <iostream>
#include <cstdio>
using namespace std;

char s[265];
int k;
char ans[105][15005];
bool num[15][15]={  
                    {1,1,1,0,1,1,1},
                    {0,0,1,0,0,1,0},
                    {1,0,1,1,1,0,1},
                    {1,0,1,1,0,1,1},
                    {0,1,1,1,0,1,0},
                    {1,1,0,1,0,1,1},
                    {1,1,0,1,1,1,1},
                    {1,0,1,0,0,1,0},
                    {1,1,1,1,1,1,1},
                    {1,1,1,1,0,1,1}
                };

void draw(int pos,bool up,bool up_left,bool up_right,bool mid,bool down_left,bool down_right,bool down)
{
    for(int i=pos;i<=pos+k+2;i++)
        for(int j=0;j<=k*2+3;j++)
            ans[j][i]=' ';
    
    for(int i=pos+1;i<=pos+k;i++)
    {
        if(up) ans[0][i]='-';
        if(mid) ans[k+1][i]='-';
        if(down) ans[(k+1)*2][i]='-';
    }

    for(int i=1;i<=k;i++)
    {
        if(up_left) ans[i][pos]='|';
        if(up_right) ans[i][pos+k+1]='|';
    }

    for(int i=k+2;i<=2*k+1;i++)
    {
        if(down_left) ans[i][pos]='|';
        if(down_right) ans[i][pos+k+1]='|';
    }
}

int main()
{
    int pos=0;
    scanf("%d",&k);
    scanf("%s",&s);
    for(int i=0;s[i];i++,pos+=k+3)
    {
        int d=s[i]-'0';
        draw(pos,num[d][0],num[d][1],num[d][2],num[d][3],num[d][4],num[d][5],num[d][6]);
    }

    for(int i=0;i<=2*k+2;i++)
        puts(ans[i]);
    //getchar();getchar();
    return 0;
}