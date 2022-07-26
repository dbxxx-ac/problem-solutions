/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-31 10:56:36 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-31 11:40:15
 */
#include <iostream>
#include <cstdio>

const int maxn = 25;
const int maxm = 25;
inline int max(int a, int b) {
    return a > b ? a : b;
}

int n, m, ans;
int worknum[maxn];
int worklist[maxn * maxm];
int needmachine[maxn][maxm];
int needtime[maxn][maxm];
int finishedtime[maxn];
bool vis[maxn][maxn * maxm];

int main() {
    std :: cin >> m >> n;
    for(int i = 1; i <= n * m; i++)
        std :: cin >> worklist[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std :: cin >> needmachine[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std :: cin >> needtime[i][j];
    
    for(int i = 1; i <= n * m; i++) {
        int now = worklist[i];
        worknum[now]++;
        int validtime = 0;
        for(int j = finishedtime[now] + 1; ; j++) {
            if(!vis[needmachine[now][worknum[now]]][j])
                validtime++;
            else validtime = 0;
            if(validtime == needtime[now][worknum[now]]) {
                for(int k = j - needtime[now][worknum[now]] + 1; k <= j; k++)
                    vis[needmachine[now][worknum[now]]][k] = true;
                finishedtime[now] = j;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        ans = max(ans, finishedtime[i]);
    std :: cout << ans << std :: endl;
    return 0;
}