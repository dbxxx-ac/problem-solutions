/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 17:19:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-18 17:44:24
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool valid(int x,int y){
    //if(x>=1&&x<=m&&y>=1&&y<=n&&a[x][y]>0) printf("%d,%d is valid!",x,y);
    return x>=1&&x<=m&&y>=1&&y<=n&&a[x][y]>0;
}

void dfs(int x,int y){
    a[x][y]=-1;
    for(int i=0;i<4;i++){
        int nxtx=x+dx[i],nxty=y+dy[i];
        if(valid(nxtx,nxty)) dfs(nxtx,nxty);
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&a[i][j]);
    
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]>0){
                //printf("Find the %dth cell at (%d,%d)\n",ans+1,i,j);
                ans++;
                dfs(i,j);
            }
/*
    for(int i=1;i<=m;i++,puts(""))
        for(int j=1;j<=n;j++,putchar(' '))
            printf("%3d",a[i][j]);*/
    printf("%d\n",ans);
    return 0;
}