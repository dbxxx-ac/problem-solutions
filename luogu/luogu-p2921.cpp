/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-12 21:16:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-12 21:53:47
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

const int maxn = 100005;

int v[maxn];

int org[maxn], siz[maxn], ent[maxn], dfn[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        v[i] = read();
    for (int i = 1; i <= n; ++i) {
        for (int u = i, times = 0; ; u = v[u], ++times) {
            if (org[u] == 0) {
                org[u] = i;
                dfn[u] = times;
            } else if (org[u] == i) {
                siz[i] = times - dfn[u];
                ent[i] = dfn[u];
                printf("%d\n", times);
                break;
            } else {
                siz[i] = siz[org[u]];
                ent[i] = times;
                if (dfn[u] < ent[org[u]])
                    ent[i] += ent[org[u]] - dfn[u];
                printf("%d\n", ent[i] + siz[i]);
                break;
            }
        }
    }
    return 0;
}