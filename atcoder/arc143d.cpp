/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-06-29 20:51:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-06-29 21:16:18
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 2e5 + 5, maxm = 2e5 + 5;

int a[maxm], b[maxm];

bool visv[maxn], vise[maxn << 1];
int head[maxn << 1], nxt[maxn << 1], to[maxn << 1], ecnt = 1;

int ans[maxm];
inline void insert(int u, int v) {
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}

void dfs(int u) {
    visv[u] = true;
    for (int &i = head[u]; i; i = nxt[i]) {
        if (vise[i])
            continue;
        vise[i] = vise[i ^ 1] = true;
        ans[i >> 1] = i & 1;
        dfs(to[i]);
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i) {
        b[i] = read();
        insert(b[i], a[i]);
        insert(a[i], b[i]);
    }

    for (int i = 1; i <= n; ++i)
        if (!visv[i])
            dfs(i);

    for (int i = 1; i <= m; ++i)
        printf("%d", ans[i]);
    return 0;
}