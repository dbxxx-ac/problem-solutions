/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 17:48:19 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-18 23:42:57
 */
#include <bits/stdc++.h>
using namespace std;

int n;
bool a[1005][1005];
int x1,x2,_y1,y2;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct status{
    int x,y,step;
};
queue<status> q;

bool valid(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n&&!a[x][y];
}

void bfs(){
    status now;
    now.x=x1;now.y=_y1;now.step=0;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nxtx=now.x+dx[i],nxty=now.y+dy[i];
            if(nxtx==x2&&nxty==y2){
                printf("%d\n",now.step+1);
                return ;
            }
            if(valid(nxtx,nxty)){
                status nxt;
                nxt.x=nxtx;nxt.y=nxty;nxt.step=now.step+1;
                a[nxtx][nxty]=1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&a[i][j]);
    scanf("%d%d%d%d",&x1,&_y1,&x2,&y2);
    
    bfs();
    return 0;
}