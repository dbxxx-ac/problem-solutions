#include <bits/stdc++.h>
#define int long long
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

const int maxn = 405;
const int maxm = 50005;

struct edge {
    int u, v, g, s;
}e[maxm];

int fa[maxn];
inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

int mst[maxn], cnt = 0;

signed main() {
    int n = read(), m = read(), G = read(), S = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), g = read(), s = read();
        e[i] = (edge){u, v, g, s};
    }

    std :: sort(e + 1, e + m + 1, [](edge x, edge y) {
        return x.g < y.g;
    });
    
    mst[0] = 0;
    int ans = LONG_LONG_MAX;

    for (int i = 1; i <= m; ++i) {
        ++cnt;
        for (int j = cnt; j; --j) {
            mst[j + 1] = mst[j];
            if (e[mst[j - 1]].s <= e[i].s) {
                mst[j] = i;
                break;
            }
        }
        
        int tnt = cnt;
        cnt = 0;
        std :: iota(fa + 1, fa + n + 1, 1);
        
        int maxs = 0;
        for (int j = 1; j <= tnt; ++j) {
            int id = mst[j];
            int u = e[id].u, v = e[id].v, s = e[id].s;
            if (uni(u, v)) {
                mst[++cnt] = id;
                maxs = s;
            }
        }

        if (cnt == n - 1)
            gmi(ans, maxs * S + e[i].g * G);
    }

    if (ans == LONG_LONG_MAX)
        ans = -1;
    
    printf("%lld\n", ans);
    return 0;
}