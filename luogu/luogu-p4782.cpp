/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-05 17:39:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-05 18:10:26
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

const int N = (int)1e6 + 5;
const int M = (int)1e6 + 5;

int sccno[N << 1];
std :: vector <int> G[N << 1];
std :: stack <int> s;
int dfn[N << 1], low[N << 1], times, snt;

inline void tarjan(int u) {
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
        } else if (!sccno[v]) {
            gmi(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        ++snt;
        for (; ;) {
            int x = s.top();
            s.pop();
            sccno[x] = snt;
            if (x == u)
                break;    
        }
    }   
}

int n;
inline void add(int u, int p, int v, int q) {
    G[u + p * n].push_back(v + q * n);
    G[v + (q ^ 1) * n].push_back(u + (p ^ 1) * n);
}

int main() {
    n = read();
    int m = read();
    while (m--) {
        int u = read(), p = read(), v = read(), q = read();
        add(u, p ^ 1, v, q);
    }
    for (int u = 1; u <= 2 * n; ++u)
        if (!dfn[u])
            tarjan(u);
    for (int u = 1; u <= n; ++u) {
        if (sccno[u] == sccno[u + n]) {
            puts("IMPOSSIBLE");
            return 0;
        }        
    }
    puts("POSSIBLE");
    for (int u = 1; u <= n; ++u)
        printf("%d ", (sccno[u] > sccno[u + n]) ? 1 : 0);
    return 0;
}