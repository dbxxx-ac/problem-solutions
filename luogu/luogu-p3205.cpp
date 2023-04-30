#include <bits/stdc++.h>
#define int long long
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

const int maxn = 2005;
const int mod = 19650827;

int f[maxn][maxn][2];
int a[maxn];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        f[i][i][0] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            // a[l] 左插 a[l + 1 .. r]，a[l] 比上次插入的要小
            if (a[l] < a[l + 1])
                f[l][r][0] = f[l + 1][r][0];
            if (a[l] < a[r])
                (f[l][r][0] += f[l + 1][r][1]) %= mod;
            // a[r] 右插 a[l .. r - 1]，a[r] 比上次插入的要大
            if (a[r] > a[l])
                f[l][r][1] = f[l][r - 1][0];
            if (a[r] > a[r - 1])
                (f[l][r][1] += f[l][r - 1][1]) %= mod;
        }
    }

    printf("%lld\n", (f[1][n][0] + f[1][n][1]) % mod);
    return 0;
}