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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = 205 << 1;

int a[maxn], f[maxn][maxn], g[maxn][maxn];
int s[maxn];

signed main() {
    int n = read();
    int n2 = (n << 1);
    for (int i = 1; i <= n; ++i)
        a[i] = a[i + n] = read();

    std :: partial_sum(a + 1, a + 1 + n2, s + 1);
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n2; ++l, ++r) {
            g[l][r] = INT_MAX;
            for (int i = l; i < r; ++i) {
                gmx(f[l][r], f[l][i] + f[i + 1][r] + s[r] - s[l - 1]);
                gmi(g[l][r], g[l][i] + g[i + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    int anf = 0, ang = INT_MAX;
    for (int l = 1, r = n; r <= n2; ++l, ++r) {
        gmx(anf, f[l][r]);
        gmi(ang, g[l][r]);
    }
    printf("%d\n%d\n", ang, anf);
    return 0;
}