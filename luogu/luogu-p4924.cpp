/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-18 00:35:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-18 00:41:34
 */
#include <iostream>
#include <cstdio>

const int maxn = 505;
int g[maxn][maxn];

int main() {
    int n,m;
    std :: cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = (i - 1) * n + j;
    
    for(int i = 1; i <= m; i++) {
        int a, b, r, z;
        std :: cin >> a >> b >> r >> z;
        if(z) {
            int tmp[maxn][maxn];
            for(int i = a - r; i <= a + r; i++)
                for(int j = b - r; j <= b + r; j++)
                    tmp[a + b - j][b - a + i] = g[i][j];
            for(int i = a - r; i <= a + r; i++)
                for(int j = b - r; j <= b + r; j++)
                    g[i][j] = tmp[i][j];
        } else {
            int tmp[maxn][maxn];
            for(int i = a - r; i <= a + r; i++)
                for(int j = b - r; j <= b + r; j++)
                    tmp[a - b + j][a + b - i] = g[i][j];
            for(int i = a - r; i <= a + r; i++)
                for(int j = b - r; j <= b + r; j++)
                    g[i][j] = tmp[i][j];
        }
    }

    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= n; j++, putchar(' '))
            printf("%d", g[i][j]);
    
    return 0;
}