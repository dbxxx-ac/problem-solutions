/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-07 04:15:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-07 05:23:10
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = (int)5e5 + 5;
const int maxm = (int)1e6 + 5;
std :: vector <int> G[maxn], T[maxn];

int dfn[maxn], low[maxn], snt = 0, times = 0, sno[maxn];
int c[maxn];
std :: stack <int> s;

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++times;
    s.push(u);

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            gmi(low[u], low[v]);
        } else if (v != fa)
            gmi(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++snt;
        for (; ;) {
            int x = s.top();
            s.pop();
            sno[x] = snt;
            ++c[snt];
            if (x == u)
                break;
        }
    }
}

const int mod = (int)1e9 + 7;
int f[maxn], ans = 0;
int p[maxm], e[maxn];

void dp(int u, int fa) {
    f[u] = p[c[u]];
    for (int v : T[u]) {
        if (v == fa)
            continue;
        dp(v, u);
        (f[u] *= (p[e[v] + 1] + f[v])) %= mod;
        e[u] += e[v] + 1;
    }
    (f[u] += mod - p[e[u]]) %= mod;

    int now = f[u];
    for (int v : T[u]) {
        if (v == fa)
            continue;
        ((now -= f[v] * p[e[u] - e[v] - 1] % mod) += mod) %= mod;
    }
    (ans += now * p[snt - 1 - e[u]] % mod) %= mod;
}

signed main() {
    int n = read(), m = read();
    for (int _ = 1; _ <= m; ++_) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }

    tarjan(1, 0);
    
    for (int u = 1; u <= n; ++u)
        for (int v : G[u])
            if (sno[u] != sno[v])
                T[sno[u]].push_back(sno[v]);
    
    p[0] = 1;
    for (int i = 1; i <= m + 3; ++i)
        p[i] = (p[i - 1] << 1) % mod;

    dp(1, 0);
    printf("%lld\n", ans * p[m - e[1]] % mod);
    return 0;
}