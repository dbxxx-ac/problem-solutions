/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-06 08:36:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-06 08:39:46
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;
const int maxm = 1005;
const int infmin = -1008610086;

int a[maxn][maxm];
int sum[maxn][maxm];

int main() {
    int n, m, c;
    std :: scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std :: scanf("%d", &a[i][j]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    
    int maxv = infmin;
    int ansx, ansy;

    for (int i = c; i <= n; ++i)
        for (int j = c; j <= m; ++j) {
            int v = sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c];
            if (maxv < v) {
                maxv = v;
                ansx = i - c + 1;
                ansy = j - c + 1;
            }
        }

    std :: printf("%d %d\n", ansx, ansy);
    return 0;
}