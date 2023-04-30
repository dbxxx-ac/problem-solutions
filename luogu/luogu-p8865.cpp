/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-01 11:11:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-05 17:36:15
 */
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
inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

const int maxn = 1005;
const int maxm = 1005;
const int mod = 998244353;

bool a[maxn][maxm];
int r[maxn][maxm], g[maxn][maxm], h[maxn][maxm];

signed main() {
    int T = read(); read();
    while (T--) {
        std :: memset(r, -1, sizeof(r));
        std :: memset(g, 0, sizeof(g));
        std :: memset(h, 0, sizeof(h));
        
        int n = read(), m = read(), C = read(), F = read();

        for (int i = 1; i <= n; ++i) {
            std :: string s = rest().first;
            for (int j = 1; j <= m; ++j)
                a[i][j] = (s[j] == '1');
        }

        for (int i = 1; i <= n; ++i)
            for (int j = m; j; --j)
                r[i][j] = a[i][j] ? -1 : (r[i][j + 1] + 1);
        
        for (int i = n; i; --i)
            for (int j = 1; j <= m; ++j)
                g[i][j] = a[i][j] ? 0 : ((g[i + 1][j] + r[i][j]) % mod);

        for (int j = 1; j <= m; ++j) {
            for (int i = n, k = n; i; --i) {
                if (a[i][j])
                    k = i - 1;
                else
                    h[i][j] = (h[i + 1][j] + r[i][j] * (k - i)) % mod;
            }
        }
        
        int c = 0, f = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] || a[i + 1][j])
                    continue;
                (c += r[i][j] * g[i + 2][j]) %= mod;
                (f += r[i][j] * h[i + 2][j]) %= mod;
            }
        }

        printf("%lld %lld\n", c * C, f * F);
    }

    return 0;
}