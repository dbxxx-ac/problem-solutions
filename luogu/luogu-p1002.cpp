/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-05 16:58:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-05 17:36:00
 */
#include <cstdio>
#include <iostream>

const int maxn = 25;
const int maxm = 25;
int n, m, hx, hy;

const int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

bool disabled[maxn][maxm];
long long dp[maxn][maxm];

bool judge(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

int main() {
    std :: cin >> n >> m >> hx >> hy;

    for (int i = 1; i <= 20; ++i)
        dp[0][i] = dp[i][0] = 1;

    for (int i = 0; i <= 8; ++i)
        if (judge(hx + dx[i], hy + dy[i])) {
                disabled[hx + dx[i]][hy + dy[i]] = true;
                dp[hx + dx[i]][hy + dy[i]] = 0;
        }
    
    for (int i = 0; i <= n; ++i)
        if (disabled[i][0])
            for (int j = i; j <= n; ++j)
                dp[j][0] = 0;
    
    for (int i = 0; i <= m; ++i)    
        if (disabled[0][i])
            for (int j = i; j <= m; ++j)
                dp[0][j] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * !disabled[i][j];
    
    std :: cout << dp[n][m] << std :: endl;
    return 0;
}