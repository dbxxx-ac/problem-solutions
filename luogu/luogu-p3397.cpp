/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-05 13:28:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-05 13:32:21
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;

int sum[maxn][maxn];

int main() {
    int n, m;
    std :: scanf("%d %d", &n, &m);
    while (m--) {
        int x1, x2, _y1, y2;
        std :: scanf("%d %d %d %d", &x1, &_y1, &x2, &y2);
        for (int i = x1; i <= x2; ++i) {
            ++sum[i][_y1];
            --sum[i][y2 + 1];
        }
    }

    for (int i = 1; i <= n; ++i, puts(""))
        for (int j = 1; j <= n; ++j, putc(' ', stdout))
            std :: printf("%d", sum[i][j] += sum[i][j - 1]);
    
    return 0;
}