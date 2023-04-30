/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-28 10:50:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-28 12:28:11
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
inline char rech() {
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

const int maxn = (int)4e5 + 5;
const int maxm = (int)4e5 + 5;
const int maxq = (int)4e5 + 5;

int eu[maxm], ev[maxm];
int siz[maxn], a[maxn];
bool del[maxm];

int fa[maxn];

int opt[maxq];
std :: vector <int> add[maxq];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

signed main() {
    int n = read(), m = read(), q = read();
    for (int i = 1; i <= m; ++i) {
        eu[i] = read();
        ev[i] = read();
    }

    int fg = q + 1;
    for (int i = 1, p = 1; i <= q; ++i) {
        char c = rech();
        if (c == 'G') {
            getchar();
            if (fg == q + 1)
                fg = i;
            for (int j = p; j < i; ++j) {
                int e = opt[j];
                add[i].push_back(e);
                del[e] = true;
            }
            p = i + 1;
        } else {
            opt[i] = read();
        }
    }

    for (int i = 1; i <= n; ++i)
        siz[i] = a[i] = read();
    
    for (int i = 1; i <= m; ++i)
        if (!del[i])
            add[q + 1].push_back(i);
    
    int ans = 0;

    std :: iota(fa + 1, fa + n + 1, 1);
    for (int i = q + 1; i; --i) if (!add[i].empty()) {
        for (int e : add[i]) {
            int u = eu[e], v = ev[e];
            u = get(u);
            v = get(v);
            if (u == v)
                continue;
            if (v == 1)
                u ^= v ^= u ^= v;
            if (u == 1)
                ans += siz[v] * i;
            siz[u] += siz[v];
            fa[v] = u;
        }
    }

    int fr = 0;
    for (int i = 1; i <= n; ++i)
        if (get(i) != 1)
            fr += a[i];
        
    printf("%llu\n", ans + (q + 1) * a[1] + fr * fg);
    return 0;
}