/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 23:56:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-04 02:14:54
 */
#include <bits/stdc++.h>
#define int long long

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


struct edge {
    int u, v, dis;
};

std :: basic_string <edge> e;

bool cmp(edge a, edge b) {
    return a.dis < b.dis;
}

const int maxn = 2505;

int deg[maxn];

struct query_set {
    int fa[maxn];
    void init(int n) {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }

    int get(int x) {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }

    void merge(int x, int y) {
        fa[get(x)] = get(y);
    }
}a, d;

inline int abs(int x) {
    return x > 0 ? x : -x;
}

signed main() {
    int n = read(), m = read(), s = read(), flower = 0;
    a.init(n);
    for (int _ = 1; _ <= m; ++_) {
        int u = read(), v = read();
        ++deg[u];
        ++deg[v];
        a.merge(u, v);
        flower += abs(u - v);
    }

    
    for (int i = 1; i <= n; ++i) {
        d.init(n);
        ++deg[s];
        ++deg[i]; // 在 s 和 i 中连边 i -> s，变为构造欧拉回路

        d.merge(a.get(s), a.get(i));

        // 将奇点两两配对连边，同时考虑到此处边权的性质，u 和 v 连，为了让他最能有连通性
        // 不连 u 和 v，而是把 u 和 v 中的所有点连成一条链
        int lst = -1LL, free = 0;
        for (int j = 1; j <= n; ++j) {
            if ((deg[j] & 1) == 0)
                continue;
            if (lst == -1) {
                lst = j;
                continue;
            }
            for (int k = lst; k < j; ++k)
                d.merge(a.get(k), a.get(k + 1));
            free += j - lst;
            lst = -1;
        }

        // 连通块连边
        e.clear();
        lst = 0;
        for (int j = 1; j <= n; ++j) {
            if (deg[j] == 0)
                continue;
            if (lst == 0 || d.get(a.get(lst)) == d.get(a.get(j))) {
                lst = j;
                continue;
            }
            edge now;
            now.u = a.get(lst);
            now.v = a.get(j);
            now.dis = j - lst;
            e += now;
            lst = j;
        }

        // 在连通块连的边中跑 MST，获得最少代价联通方案
        std :: sort(e.begin(), e.end(), cmp);
        for (int i = 0; i < e.length(); ++i) {
            edge now = e[i];
            if (d.get(now.u) != d.get(now.v)) {
                d.merge(now.u, now.v);
                free += now.dis * 2; // 为了连通时不破坏奇偶性，只能连两次咯
            }
        }

        // 把加来的 i -> s 这条边还回去
        --deg[s];
        --deg[i];
        printf("%lld ", flower + free);
    }
    puts("");
    return 0;
}

/*
4 3 1
1 2
4 2
3 1
*/