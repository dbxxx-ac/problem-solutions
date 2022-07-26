/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-17 09:59:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-17 10:09:59
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,startx,starty;
int a[440][440];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,-2,-1,1,2};

struct horse{
    int x,y;
    int step;
};

queue<horse> q;

bool valid(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&a[x][y]==-1;
}
void bfs(){
    horse now;
    now.x=startx;now.y=starty;now.step=0;
    q.push(now);

    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nxtx=dx[i]+now.x,nxty=dy[i]+now.y;
            if(valid(nxtx,nxty)){
                horse nxt;
                nxt.x=nxtx;nxt.y=nxty;a[nxtx][nxty]=nxt.step=now.step+1;
                q.push(nxt);
            }
        }
    }
    
    return ;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&startx,&starty);
    memset(a,-1,sizeof(a));
    a[startx][starty]=0;
    bfs();

    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%-5d",a[i][j]);
    
    return 0;
}