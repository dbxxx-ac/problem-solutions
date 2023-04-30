/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 21:08:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 21:27:19
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

const int maxn = (int)2e5 + 5;
const int lg = 23;

typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];

int far[maxn][lg], dep[maxn], times = 0;
int ifn[maxn], ofn[maxn], dis[maxn];
int us[maxn], vs[maxn], wei[maxn];

void dfs(int u, int fa) {
    far[u][0] = fa;
    dep[u] = dep[fa] + 1;
    ifn[u] = ++times;
    
    for (int i = 1; i < lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    
    for (pii e : G[u]) {
        int v = e.first, id = e.second;
        int w = wei[id];
        if (v ^ fa) {
            dis[v] = dis[u] + w;
            dfs(v, u);
        }
    }

    ofn[u] = times;
    
    return ;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v])
        u ^= v ^= u ^= v;

    for (int i = 0; i < lg; ++i) {
        if ((dep[u] - dep[v]) & (1 << i))
            u = far[u][i];
    }
    
    if (u == v)
        return u;
    
    for (int i = lg - 1; i >= 0; --i) {
        if (far[u][i] != far[v][i]) {
            u = far[u][i];
            v = far[v][i];
        }
    }
    
    return far[u][0];
}

int c[maxn];

inline int lowbit(int x) {
    return x & (-x);
}

inline void add(int x, int v) {
    for (; x < maxn; x += lowbit(x))
        c[x] += v;
}

inline int sum(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += c[x];
    return ans;
}

signed main() {
    int n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        us[i] = u;
        vs[i] = v;
        wei[i] = w;
    }

    dfs(1, 0);

    int q = read();
    while (q--) {
        int op = read();
        if (op == 1) {
            int id = read(), w2 = read();
            int u = us[id], v = vs[id], w1 = wei[id];
            if (dep[u] < dep[v])
                std :: swap(u, v);
            add(ifn[u], w2 - w1);
            add(ofn[u] + 1, w1 - w2);
            wei[id] = w2;
        } else {
            int u = read(), v = read();
            int p = lca(u, v);
            printf("%lld\n", sum(ifn[u]) + sum(ifn[v]) - 2 * sum(ifn[p])
            + dis[u] + dis[v] - 2 * dis[p]);
        }
    }

    return 0;
}