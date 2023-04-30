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

const int maxn = 105 << 1;

int a[maxn], f[maxn][maxn];

signed main() {
    int n = read();
    int n2 = (n << 1);
    for (int i = 1; i <= n; ++i)
        a[i] = a[i + n] = read();
    
    a[n2 + 1] = a[1];

    for (int len = 2; len <= n; ++len)
        for (int l = 1, r = len; r <= n2; ++l, ++r)
            for (int i = l; i < r; ++i)
                gmx(f[l][r], f[l][i] + f[i + 1][r] + a[l] * a[i + 1] * a[r + 1]);
    
    int ans = 0;
    for (int l = 1, r = n; r <= n2; ++l, ++r)
        gmx(ans, f[l][r]);
    
    printf("%d\n", ans);
    return 0;
}