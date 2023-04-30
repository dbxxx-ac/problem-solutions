/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-27 09:44:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-27 09:58:40
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
const int maxn = (int)1e4 + 5;
const int maxm = (int)1e5 + 5;

int a[maxn], siz[maxn], sccno[maxn], snt = 0;
int low[maxn], dfn[maxn], times = 0;
int us[maxm], vs[maxm];

namespace org {
    std :: vector <int> G[maxn];
}
namespace dag {
    std :: vector <int> G[maxn];
}

std :: stack <int> s;

void tarjan(int u) {
    dfn[u] = low[u] = ++times;
    s.push(u);
    for (int v : org :: G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
        } else if (!sccno[v])
            gmi(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++snt;
        for (; ;) {
            int x = s.top();
            s.pop();
            sccno[x] = snt;
            siz[snt] += a[x];
            if (x == u)
                break;
        }
    }
}

int sum[maxn], ind[maxn];

inline int topsort() {
    std :: queue <int> q;
    for (int u = 1; u <= snt; ++u)
        if (ind[u] == 0) {
            sum[u] = siz[u];
            q.push(u);
        }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : dag :: G[u]) {
            gmx(sum[v], sum[u] + siz[v]);
            --ind[v];
            if (ind[v] == 0)
                q.push(v);
        }
    }

    int ans = 0;
    for (int u = 1; u <= snt; ++u)
        gmx(ans, sum[u]);
    return ans;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = us[i] = read(), v = vs[i] = read();
        org :: G[u].push_back(v);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u);
    
    for (int i = 1; i <= m; ++i) {
        int u = sccno[us[i]], v = sccno[vs[i]];
        if (u == v)
            continue;
        dag :: G[u].push_back(v);
        ++ind[v];
    }

    printf("%d\n", topsort());
    return 0;
}