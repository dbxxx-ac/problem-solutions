/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-16 23:07:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-16 23:33:32
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int a[35][35];
bool vis[35][35];
int nxtpos[2][4]={{1,0,-1,0},{0,1,0,-1}};

bool valid(int x,int y){
    return (x>=0&&x<=n+1&&y>=0&&y<=n+1&&a[x][y]==2&&!vis[x][y]);
}

void dfs(int x,int y){
    if(vis[x][y]) return ;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int nxtx=x+nxtpos[0][i],nxty=y+nxtpos[1][i];
        if(valid(nxtx,nxty)){
            a[nxtx][nxty]=0;
            dfs(nxtx,nxty);
        }
        //else printf("%d,%d is not valid!\n",nxtx,nxty);
    }
    return ;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j]) a[i][j]=2;
        }
    
    for(int i=0;i<=n+1;i++)
        a[i][0]=a[i][n+1]=a[n+1][i]=a[0][i]=2;
    
    dfs(0,0);
    
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++,putchar(' '))
            printf("%d",a[i][j]);
    
    return 0;
}