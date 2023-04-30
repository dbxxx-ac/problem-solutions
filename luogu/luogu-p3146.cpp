/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-18 02:13:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-18 02:45:31
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

const int maxn = 255;

int f[maxn][maxn];

int main() {
    int n = read(), ans = 0;
    for (int i = 1; i <= n; ++i)
        gmx(ans, f[i][i] = read());
    
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            for (int i = l; i < r; ++i)
                if (f[l][i] == f[i + 1][r] && f[l][i]) {
                    f[l][r] = f[l][i] + 1;
                    gmx(ans, f[l][r]);
                }
        }
    }

    printf("%d\n", ans);
    return 0;
}