/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 10:11:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 10:24:57
 */
#include <iostream>
#include <cstdio>
#include <climits>

const int maxn = 55;
const int maxm = 55;

char g[maxn][maxm];

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m;
    int ans = INT_MAX;
    std :: cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std :: cin >> g[i][j];
    
    for(int k = 1; k <= n - 2; k++)
        for(int l = k + 1; l <= n - 1; l++) {
            int tmp = 0;
            for(int i = 1; i <= k; i++)
                for(int j = 1; j <= m; j++)
                    if(g[i][j] != 'W')
                        tmp++;
            for(int i = k + 1; i <= l; i++)
                for(int j = 1; j <= m; j++)
                    if(g[i][j] != 'B')
                        tmp++;
            for(int i = l + 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                    if(g[i][j] != 'R')
                        tmp++;
            ans = min(ans, tmp);
        }
    
    std :: cout << ans << std :: endl;
    return 0;
}