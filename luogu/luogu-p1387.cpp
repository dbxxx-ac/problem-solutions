/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-26 10:16:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-26 10:28:00
 */
#include <iostream>
#include <cstdio>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f)
        return x;
    return ~(x - 1);
}

const int maxn = 105;
const int maxm = 105;
int a[maxn][maxm];
int sum[maxn][maxm];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = read();
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    
    int ans = 0;
    for (int len = 1; len <= std :: min(n, m); ++len)
        for (int i = len; i <= n; ++i)
            for (int j = len; j <= m; ++j)
                if (sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] == len * len)
                    ans = len;
    
    std :: printf("%d\n", ans);
    return 0;
}