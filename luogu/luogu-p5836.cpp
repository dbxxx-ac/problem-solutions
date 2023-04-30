/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-20 15:41:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-20 15:54:32
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
inline char rech() {
    char ch = getchar();
    while (!isgraph(ch))
        ch = getchar();
    return ch;
}

const int maxn = (int)1e5 + 5;

std :: vector <int> G[maxn];
int a[maxn], top[maxn];

void dfs(int u, int ls) {
    top[u] = (a[u] == a[ls]) ? top[ls] : u;
    for (int v : G[u])
        if (v != ls)
            dfs(v, u);
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = ((rech() == 'H') ? 1 : 0);
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    top[0] = 1; // to get the correct top[1]
    dfs(1, 0);
    while (m--) {
        int u = read(), v = read(), c = ((rech() == 'H') ? 1 : 0);
        if (a[u] != c && a[v] != c && top[u] == top[v])
            putchar('0');
        else    
            putchar('1');
    }
    return 0;
}