#include <bits/stdc++.h>
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

const int maxn = (int)1e5 + 5;
const int maxq = (int)1e5 + 5;

int fa[maxn], siz[maxn];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

struct edge {
    int u, v, w;
} e[maxn];

struct query {
    int k, v, id;
} qst[maxq];

int ans[maxq];

inline bool uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v)
        return false;
    if (siz[u] > siz[v])
        u ^= v ^= u ^= v;
    
    fa[u] = v;
    siz[v] += siz[u];
    return true;
}

int main() {
    int n = read(), q = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        e[i] = (edge){u, v, w};
    }
    
    std :: sort(e + 1, e + n, [](edge x, edge y) {
        return x.w > y.w;
    });

    for (int i = 1; i <= q; ++i) {
        int k = read(), v = read();
        qst[i] = (query){k, v, i};
    }

    std :: sort(qst + 1, qst + q + 1, [](query x, query y) {
        return x.k > y.k;
    });

    std :: iota(fa + 1, fa + n + 1, 1);
    std :: fill(siz + 1, siz + n + 1, 1);
    
    for (int i = 1, cur = 1; i <= q; ++i) {
        int k = qst[i].k;
        while (e[cur].w >= k)
            uni(e[cur].u, e[cur].v),
            ++cur;
        ans[qst[i].id] = siz[get(qst[i].v)] - 1;
    }

    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}