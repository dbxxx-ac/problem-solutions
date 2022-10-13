/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-04 14:11:52 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-05 03:31:48
 */
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

const int maxn = (int)5e5 + 5;

std :: vector <int> G[maxn];

int dfn[maxn], low[maxn], times;
std :: stack <int> s;

inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

std :: vector <int> vcc[maxn];
int vnt = 0;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            gmi(low[u], low[v]);
            if (low[v] >= dfn[u]) {
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
        } else if (v != fa)
            gmi(low[u], dfn[v]);
    }

    if (fa == 0 && G[u].empty()) {
        vcc[++vnt].push_back(u);
    }
}

int main() {
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        if (u == v)
            continue;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u, 0);
    
    printf("%d\n", vnt);

    for (int i = 1; i <= vnt; ++i) {
        printf("%d ", (int)vcc[i].size());
        for (int u : vcc[i])
            printf("%d ", u);
        puts("");
    }

    return 0;
}