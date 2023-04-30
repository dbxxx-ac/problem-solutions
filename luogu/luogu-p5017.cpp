/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-11 00:44:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-11 01:22:25
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
inline int min(int a, int b) {
    return a < b ? a : b;
}
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = 505;
const int maxm = 105;

int t[maxn], f[maxn][maxm];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        t[i] = read();
    std :: sort(t + 1, t + 1 + n);

    t[0] = -105;
    std :: memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= min(m - 1, t[i + 1] - t[i]); ++k) {
            for (int j = i + 1, tot = t[i + 1]; j <= n; ++j, tot += t[j]) {
                int T = max(t[i] + k + m, t[j]);
                gmi(f[j][T - t[j]],
                f[i][k] + T * (j - i) - tot);
            }
        }
    }

    int ans = INT_MAX;
    for (int k = 0; k < m; ++k)
        gmi(ans, f[n][k]);
    printf("%d\n", ans);
    return 0;
}