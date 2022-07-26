/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-22 10:31:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-22 12:37:36
 */
#include <iostream>
#include <cstdio>

const int maxn = 25;
int n,sum;
bool vis[maxn];
int ans[maxn];
int c[maxn];

bool dfs(int nownum, int nowsum, int step) {
    if (nowsum > sum) return false;
    if (step == n) {
        if(nowsum == sum) {
            ans[n] = nownum;
            return true;
        }
    }

    vis[nownum] = true;
    for (int j = 1; j <= n; j++) {
        if (vis[j]) continue;
        if(dfs(j,nowsum+c[step]*j,step+1)) {
            ans[step] = nownum;
            return true;
        }
    }

    vis[nownum] = false;
    return false;
}

void pastri() {
    c[0] = c[n-1] = 1;
    if (n == 1) return ; 
    for (int i = 1; i * 2 < n; i++)
        c[i] = c[n-i-1] = (n-i) * c[i-1] / i;
}

int main() {
    scanf("%d%d",&n,&sum);
    pastri();

    if (dfs(0,0,0)) 
        for (int i = 1; i <= n; i++)
            printf("%d ",ans[i]);

    puts("");
    return 0;
}