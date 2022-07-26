/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 15:09:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-18 16:07:20
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[505][505];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct flood{
    int x,y;
};

queue<flood> q;

bool valid(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&!a[x][y];
}

void bfs(int startx,int starty){
    flood now;
    now.x=startx;now.y=starty;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nxtx=dx[i]+now.x,nxty=dy[i]+now.y;
            if(valid(nxtx,nxty)){
                flood nxt;
                nxt.x=nxtx;nxt.y=nxty;a[nxtx][nxty]=1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='0') a[i][j]=0;
            if(c=='*') a[i][j]=2;
        }


    for(int i=1;i<=n;i++){
        if(!a[i][1]){
            a[i][1]=1;
            bfs(i,1);
        }
        if(!a[i][m]){
            a[i][m]=1;
            bfs(i,m);
        } 
    }

    for(int i=1;i<=m;i++){
        if(!a[1][i]){
            a[1][i]=1;
            bfs(1,i);
        }
        if(!a[n][i]){
            a[n][i]=1;
            bfs(n,i);
        }
    }
    /*
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++,putchar(' '))
            printf("%d",a[i][j]);
    */
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j])
                ans++;

    printf("%d\n",ans);
    return 0;
}