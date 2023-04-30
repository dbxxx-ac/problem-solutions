/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-20 02:13:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-20 02:17:18
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
inline int max(int a, int b) {
    return a > b ? a : b;
}

const int maxn = 2005;

int f[maxn][maxn];
int a[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        f[i][i] = a[i] * n;
    }
    
    for (int len = 2; len <= n; ++len)
        for (int l = 1, r = len; r <= n; ++l, ++r)
            f[l][r] = max(f[l + 1][r] + a[l] * (n - len + 1),
                        f[l][r - 1] + a[r] * (n - len + 1));
    
    printf("%d\n", f[1][n]);

    return 0;
}