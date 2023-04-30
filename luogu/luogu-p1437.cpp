/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-10 10:47:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-10 12:26:03
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
const int maxn = 55;
const int maxm = 1205;

int a[maxn][maxn], s[maxn][maxn];
int f[maxn][maxn][maxm];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - i + 1; ++j)
            a[i][j] = read();
    
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            s[i][j] = s[i - 1][j] + a[i][j];
    
    for (int j = 1; j <= n; ++j)
        for (int i = 0; i <= n; ++i)
            for (int k = i; k <= m; ++k)
                for (int l = 0; l <= i + 1; ++l) {
                    gmx(f[i][j][k],
                    f[l][j - 1][k - i] + s[i][j]);
                    // gmx(ans, f[i][j][k]);
                    // printf("%d %d %d %d\n", ans, i, j, k);
                    // 所有状态不一定都合法
                }

    std :: cout << std :: max(f[0][n][m], f[1][n][m]) << std :: endl;
    return 0;
}