/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-27 18:48:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-27 19:06:25
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int mod = 10007;
const int maxn = 200005;
std :: vector <int> G[maxn];
int a[maxn];

signed main() {
    int n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u)
        a[u] = read();

    int mx = 0;
    for (int u = 1; u <= n; ++u) {
        if ((int)G[u].size() > 1) {
            std :: nth_element(G[u].begin(), G[u].begin() + 1, G[u].end(), [](int p, int q) {
                return a[p] > a[q];
            });
            gmx(mx, a[G[u][0]] * a[G[u][1]]);
        }
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        int sum = 0, sqsum = 0;
        for (int v : G[u]) {
            (sum += a[v]) %= mod;
            (sqsum += a[v] * a[v]) %= mod;
        }
        (ans += (sum * sum % mod - sqsum + mod) % mod) %= mod;
    }

    printf("%lld %lld\n", mx, ans);
    return 0;
}