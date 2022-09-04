/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-28 20:50:42 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2022-07-28 20:50:42 
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

const int maxn = int(1e5) + 5;
const int maxm = int(2e5) + 5;

struct edge {
    int to, nxt, w;
}e[maxm * 2];

int head[maxn], ecnt = 1;

inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

bool p[maxm];
int l[maxn], r[maxn];
int dis1[maxn], disn[maxn];

bool fl[maxn];

std :: priority_queue <std :: pair <int, int> > q;

void dij1(int n) {
    std :: memset(dis1, 0x3f, sizeof(dis1));
    dis1[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis1[u] != 0)
            continue;
        // std :: cout << u << std :: endl;
        for (int i = head[u]; i; i = e[i].nxt) {
            if (i & 1)
                continue;
            int v = e[i].to, w = e[i].w;
            if (dis1[v] >= dis1[u] + w) {
                if (dis1[v] > dis1[u] + w) {
                    dis1[v] = dis1[u] + w;
                    if (v == n)
                        continue;
                    q.emplace(-dis1[v], v);
                    if (!fl[v])
                        l[v] = l[u];
                }
                if (v == n)
                    continue;
                if (!fl[v] && l[v] > l[u])
                    l[v] = l[u];
            }
        }
    }
}

std :: basic_string <int> f[maxm];
std :: basic_string <int> g[maxm];

void dijn(int n) {
    std :: memset(disn, 0x3f, sizeof(disn));
    disn[n] = 0;
    q.emplace(0, n);
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + disn[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            if ((i & 1) == 0)
                continue;
            // printf("%d %d\n", u, e[i].to);
            int v = e[i].to, w = e[i].w;
            if (disn[v] >= disn[u] + w) {
                if (disn[v] > disn[u] + w) {
                    disn[v] = disn[u] + w;
                    if (v == 1)
                        continue;
                    q.emplace(-disn[v], v);
                    if (!fl[v])
                        r[v] = r[u];
                }
                if (v == 1)
                    continue;
                if (!fl[v] && r[v] < r[u])
                    r[v] = r[u];
            }
        }
    }
}

std :: multiset <int> s;

int main() {
    int n = read(), m = read(), k = read();
    for (int _ = 1; _ <= m; ++_) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    std :: memset(l, 0x3f, sizeof(l));
    l[1] = 1;
    for (int i = 1; i <= k; ++i) {
        int x = read();
        p[x] = true;
        int v = e[x << 1].to;
        fl[v] = true;
        // printf("%d\n", v);
        l[v] = i + 1;
        r[v] = i;
    }

    dij1(n);
    dijn(n);


    // for (int i = 1; i <= n; ++i)
    //     printf("%d\n", l[i]);

    for (int i = 2; i <= ecnt; i += 2) {
        if (p[i >> 1])
            continue;
        int u = e[i ^ 1].to, v = e[i].to, w = e[i].w;
        if (l[u] <= r[v]) {
            int d = dis1[u] + w + disn[v];
            // printf("%d %d %d %d %d\n", u, v, l[u], r[v], d);
            f[l[u]] += d;
            g[r[v]] += d;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (auto d : f[i])
            s.insert(d);

        if (!s.empty())
            printf("%d\n", *s.begin());
        else
            puts("-1");

        for (auto d : g[i])
            s.erase(s.find(d));
    }

    return 0;
}

/*
4 5 2
1 2 2
1 3 2
3 4 4
3 2 1
2 4 3
1 5

4 7 2
1 2 1
2 4 1
2 3 1
3 1 1
4 2 1
1 3 100
3 4 100
1 2

*/
/* died.
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

const int maxn = int(1e5) + 5;
const int maxm = int(2e5) + 5;

struct edge {
    int to, nxt, w;
}e[maxm];

int head[maxn], ecnt = 0;
int idx[maxn], vtx[maxn], sdi[maxm], suf[maxm];

bool ban[maxm];

inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

int dis[maxn];
std :: priority_queue <std :: pair <int, int> > q;
std :: priority_queue <std :: pair <int, int> > p;

void dijkstra(int s) {
    dis[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            if (ban[i])
                continue;
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (idx[v] != 0) {
                    p.emplace((dis[v] + suf[idx[v]]) * -1, idx[v]);
                }
                q.emplace(-dis[v], v);
            }
        }
    }
}

int main() {
    int n = read(), m = read(), l = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
    }

    for (int i = 1; i <= l; ++i) {
        int x = read();
        int v = e[x].to;
        sdi[i] = e[x].w;
        idx[v] = i + 1;
        vtx[i + 1] = v;
        ban[x] = true;
    }

    for (int i = l; i >= 1; --i) {
        suf[i] = suf[i + 1] + sdi[i];
    }

    vtx[1] = idx[1] = 1;
    dijkstra(1);

    for (int i = 1; i <= l; ++i) {
        while (!p.empty() && p.top().second <= i) { // 相当于 < i + 1
        // 如果这个点 skip 到了 i + 1 前面，是不可能通行的，因为 i, i + 1 是断边
            p.pop();
        // 可以直接 pop 因为后面 i 只可能更大，仍然不可能通行
        }
        if (p.empty()) {
            puts("-1");
        } else {
            printf("%d\n", -p.top().first);
        }
        dis[vtx[i + 1]] = dis[vtx[i]] + sdi[i];
        dijkstra(vtx[i + 1]);
    }

    return 0;
}
*/