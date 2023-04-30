/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-18 18:32:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-18 19:05:43
 */
#include <bits/stdc++.h>
#define int unsigned long long
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}
inline int max(int a, int b) {
    return a > b ? a : b;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = (int)1e3 + 5;
std :: vector <int> G[maxn];
std :: vector <int> vcc[maxn];
std :: stack <int> s;

int dfn[maxn], low[maxn], times, vnt;
bool isc[maxn];

inline void tarjan(int u) {
    dfn[u] = low[u] = ++times;
    s.push(u);
    int ch = 0;

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
            if (low[v] == dfn[u]) {
                ++ch;
                if (u != 1 || ch > 1)
                    isc[u] = true;
                
                ++vnt;
                while (!s.empty()) {
                    int x = s.top();
                    s.pop();
                    vcc[vnt].push_back(x);
                    if (x == v)
                        break;
                }
                vcc[vnt].push_back(u);
            }
        } else
            gmi(low[u], dfn[v]);
    }
}

inline void init(int n) {
    while (!s.empty())
        s.pop();
    for (int u = 1; u <= n; ++u)
        G[u].clear();
    for (int i = 1; i <= vnt; ++i)
        vcc[i].clear();
    std :: memset(low, 0, sizeof(low));
    std :: memset(dfn, 0, sizeof(dfn));
    std :: memset(isc, 0, sizeof(isc));
    times = vnt = 0;
}

signed main() {
    int T = 0, m = 0;
    while ((m = read()) && m) {
        int n = 0, p = 0, q = 1;
        while (m--) {
            int u = read(), v = read();
            gmx(n, max(u, v));
            G[u].push_back(v);
            G[v].push_back(u);
        }

        tarjan(1);

        for (int i = 1; i <= vnt; ++i) {
            int siz = vcc[i].size(), cnt = 0;
            for (int u : vcc[i])
                if (isc[u])
                    ++cnt;
            if (cnt == 0) {
                p = 2;
                q = siz * (siz - 1) / 2;
            } else if (cnt == 1) {
                ++p;
                q *= siz - 1;
            }
        }

        printf("Case %llu: %llu %llu\n", ++T, p, q);
        init(n);
    }
}