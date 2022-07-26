/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-19 23:01:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-19 23:41:37
 */

/* MLE 70
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
const int maxn2 = 1000005;

int n;
int fa[maxn2],u[maxn2];
bool a[maxn][maxn];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; 

int find(int x){
    return fa[x] == x?x:fa[x] = find(fa[x]);
}

void merge(int a,int b){
    int fa1 = find(a), fa2 = find(b);
    if(fa1 != fa2){
        u[fa1] += u[fa2];
        fa[fa2] = fa[fa1];
    }
}

bool valid(int x,int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int dfs(int x,int y){
    int ind = x*n+y;
    if(fa[ind] != -1) return find(ind);
    fa[ind] = ind;
    u[ind] = 1;

    for(int i=0;i<4;i++){
        int nxtx = x+dx[i], nxty = y+dy[i];
        if(valid(nxtx,nxty) && a[x][y]!=a[nxtx][nxty])
            merge(ind,dfs(nxtx,nxty));
    }
    
    return find(ind);
}

int main(){
    int T;
    scanf("%d%d",&n,&T);
    memset(fa,-1,sizeof(fa));
    for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= n; j++)
            scanf("%1d",&a[i][j]);

    while(T--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",u[dfs(x,y)]);
    }
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
const int maxn2 = 1000005;

int n;
int fa[maxn2], u[maxn2];
char a[2][maxn];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b){
    int fa1 = find(a), fa2 = find(b);
    if (fa1 != fa2){
        u[fa1] += u[fa2];
        fa[fa2] = fa[fa1];
    }
}

int main(){
    int T;
    scanf("%d%d", &n, &T);
    memset(fa, -1, sizeof(fa));
    for (int i = 0; i < n; i++){
        scanf("%s", a[i & 1]);
        for (int j = 0; j < n; j++){
            int ind = i * n + j;
            fa[ind] = ind;
            u[ind] = 1;
            if (i && a[(i - 1) & 1][j] != a[i & 1][j])
                merge(ind - n, ind);
            if (j && a[i & 1][j - 1] != a[i & 1][j])
                merge(ind, ind - 1);
        }
    }

    while (T--){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", u[find(x * n - n + y - 1)]);
    }
    return 0;
}