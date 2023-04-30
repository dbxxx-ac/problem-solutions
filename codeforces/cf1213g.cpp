#include <bits/stdc++.h>
#define int long long
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = (int)2e5 + 5;
const int maxq = (int)2e5 + 5;

int fa[maxn], siz[maxn];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

struct edge {
    int u, v, w;
} e[maxn];

typedef std :: pair <int, int> pii;
pii qst[maxq];

int ans[maxq];

inline void uni(int u, int v) {
    if (siz[u] > siz[v])
        u ^= v ^= u ^= v;
    
    fa[u] = v;
    siz[v] += siz[u];
}

signed main() {
    int n = read(), q = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        e[i] = (edge){u, v, w};
    }
    
    std :: sort(e + 1, e + n, [](edge x, edge y) {
        return x.w < y.w;
    });

    for (int i = 1; i <= q; ++i) {
        int k = read();
        qst[i] = std :: make_pair(k, i);
    }

    std :: sort(qst + 1, qst + q + 1);
    std :: iota(fa + 1, fa + n + 1, 1);
    std :: fill(siz + 1, siz + n + 1, 1);
    
    e[n].w = INT_MAX;

    for (int i = 1, cur = 1; i <= q; ++i) {
        int k = qst[i].first, id = qst[i].second;
        ans[id] = ans[qst[i - 1].second];
        
        while (e[cur].w <= k) {
            int u = e[cur].u, v = e[cur].v;
            u = get(u);
            v = get(v);
            if (u != v) {
                ans[id] += siz[u] * siz[v];
                uni(u, v);
            }
            ++cur;
        }
    }
    

    for (int i = 1; i <= q; ++i)
        printf("%lld ", ans[i]);
    return 0;
}