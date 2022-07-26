#include <iostream>
#include <cstdio>

const int maxn = 205;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int r,c,ans;
int a[maxn][maxn],dp[maxn][maxn];

int max(int a,int b) {
    return a > b ? a : b;
}

bool valid(int x,int y) {
    return x > 0 && y > 0 && x <= r && y <= c;
}

int dfs(int x,int y) {
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nxtx = x + dx[i];
        int nxty = y + dy[i];
        if(valid(nxtx,nxty) && a[nxtx][nxty] < a[x][y]) {
            dfs(nxtx,nxty);
            dp[x][y]=max(dp[x][y],dp[nxtx][nxty] + 1);
        }
    }
    
    return dp[x][y];
}

int main() {
    scanf("%d %d",&r,&c);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            scanf("%d",&a[i][j]);
    
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            ans = max(ans,dfs(i,j));

    printf("%d\n",ans);
    return 0;
}