/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-05 12:52:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-05 13:08:55
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,t,ans;
int startx,starty,endx,endy;
bool invalid[15][15];
int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};

bool isvalid(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&!invalid[x][y];
}

void dfs(int x,int y){
    if(x==endx&&y==endy){
        ans++;
        return ;
    }
    for(int i=0;i<4;i++){
        int nxtx=x+dx[i];
        int nxty=y+dy[i];
        if(isvalid(nxtx,nxty)){
            invalid[nxtx][nxty]=true;
            dfs(nxtx,nxty);
            invalid[nxtx][nxty]=false;
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
    invalid[startx][starty]=true;
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        invalid[x][y]=true;
    }
    dfs(startx,starty);
    printf("%d\n",ans);
    return 0;
}