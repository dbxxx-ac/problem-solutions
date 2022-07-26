/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 20:32:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-06 21:25:25
 */
#include <bits/stdc++.h>

const int maxn = 2005;
const int maxm = (maxn << 1) + 5;
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}
inline int min(int a, int b) {
    return a < b ? a : b;
}

int n;
struct edge {
    int to, nxt;
}e[maxm];
int head[maxn], cnt = 0, siz[maxn];
inline void insert(int u, int v) {
    ++siz[u];
    ++siz[v];
    e[++cnt] = (edge){v, head[u]};
    e[++cnt] = (edge){u, head[v]};
    head[u] = head[v] = cnt;
}

int num[maxn];
int link_pre[maxn][maxn], link_nxt[maxn][maxn], link_len[maxn][maxn];
int front_root[maxn][maxn], back_root[maxn][maxn];

int ending;
void dfs(int u, int last) {
    if (last == n + 1) {
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (front_root[u][v] == v && (link_pre[u][last] != back_root[u][v] || siz[u] <= link_len[u][front_root[u][v]]))
                dfs(v, u);
        }
    } else {
        if (back_root[u][last] == last) {
            if (link_pre[u][n + 1] == 0 && (link_nxt[u][n + 1] != front_root[u][last] || siz[u] == link_len[u][front_root[u][last]]))
                ending = min(ending, u);
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (front_root[u][v] != front_root[u][last] && front_root[u][v] == v && link_nxt[u][n + 1] != v)
                    if (link_nxt[u][n + 1] != front_root[u][last] || link_pre[u][n + 1] != back_root[u][v] || link_len[u][front_root[u][last]] + link_len[u][front_root[u][v]] >= siz[u])
                        dfs(v, u);
            }
        } else
            dfs(link_nxt[u][last], u);
    }
}

bool dfs2(int u, int last) {
    if (u == ending) {
        link_pre[u][n + 1] = last;
        link_nxt[u][last] = n + 1;
        return true;
    }
    if (n + 1 == last) {
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (front_root[u][v] == v && (link_pre[u][n + 1] != back_root[u][v] || siz[u] < link_len[u][front_root[u][v]]))
                if (dfs2(v, u))  {
                    link_pre[u][v] = n + 1;
                    link_nxt[u][n + 1] = v;
                    return true;
                }
        }
    } else {
        if (back_root[u][last] == last) {
            if (link_pre[u][n + 1] == 0 && (link_nxt[u][n + 1] != front_root[u][last] || siz[u] == link_len[u][front_root[u][last]]))
                ending = min(ending, u);
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (front_root[u][v] != front_root[u][last] && front_root[u][v] == v && link_nxt[u][n + 1] != v)
                    if (link_nxt[u][n + 1] != front_root[u][last] || link_pre[u][n + 1] != back_root[u][v] || link_len[u][front_root[u][last]] + link_len[u][front_root[u][v]] >= siz[u])
                        if (dfs2(v, u)) {
                            link_pre[u][v] = last;
                            link_nxt[u][last] = v;
                            for (int i = front_root[u][last]; i && i != n + 1; i = link_nxt[u][i]) {
                                front_root[u][i] = front_root[u][last];
                                back_root[u][i] = back_root[u][last];
                            }
                            link_len[u][front_root[u][last]] += link_len[u][v];
                            return true;
                        }
            }
        } else
            dfs2(link_nxt[u][last], u);        
    }
    return false;
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            num[i] = read();

        std :: memset(siz, 0, sizeof(siz));
        std :: memset(head, 0, sizeof(head));
        std :: memset(link_len, 0, sizeof(link_len));
        std :: memset(link_pre, 0, sizeof(link_pre));
        std :: memset(link_nxt, 0, sizeof(link_nxt));
        std :: memset(front_root, 0, sizeof(front_root));
        std :: memset(back_root, 0, sizeof(back_root));
        
        for (int i = 1; i <= n - 1; ++i) {
            int u = read(), v = read();
            insert(u, v);
            link_pre[u][v] = link_nxt[u][v] = link_pre[v][u] = link_nxt[v][u] = 0;
            link_len[u][v] = link_len[v][u] = 1;
            front_root[u][v] = back_root[u][v] = v;
            front_root[v][u] = front_root[v][u] = u;
        }
        for (int i = 1; i <= n; ++i) {
            ending = n + 1;
            dfs(num[i], n + 1);
            dfs2(num[i], n + 1);
            std :: printf("%d ", ending);
        }
        puts("");
    }
    return 0;
}