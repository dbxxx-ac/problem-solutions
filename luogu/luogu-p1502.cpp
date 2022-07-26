/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-11 17:00:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-11 17:02:26
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

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
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxn = 10005;

struct segment {
    int x, y, y2, l;
    segment(){}
    segment(int _x, int _y, int _y2, int _l) {
        x = _x;
        y = _y;
        y2 = _y2;
        l = _l;
    }

    const bool operator < (const segment &b) {
        if (this -> x == b.x) return this -> l > b.l;
        return this -> x < b.x;
    }
}s[maxn << 1];

int v[maxn << 3], laz[maxn << 3];
int d[maxn << 1];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return (p << 1) | 1;
}

inline void update(int p) {
    v[p] = std :: max(v[lson(p)], v[rson(p)]);
}

void pushdown(int p, int l, int r) {
    if (laz[p] == 0)
        return ;
    v[p] += laz[p];
    if (l != r) {
        laz[lson(p)] += laz[p];
        laz[rson(p)] += laz[p];
    }
    laz[p] = 0;
}

void modify(int p, int l, int r, int v, int s, int t) {
    if (l <= s && t <= r) {
        laz[p] += v;
        return ;
    }

    int mid = s + t >> 1;
    if (l <= mid)
        modify(lson(p), l, r, v, s, mid);
    if (r > mid)
        modify(rson(p), l, r, v, mid + 1, t);
    pushdown(lson(p), s, mid);
    pushdown(rson(p), mid + 1, t);
    update(p);
}

int main() {
    int T = read();
    while (T--) {
        int n = read(), w = read(), h = read();
        std :: memset(v, 0, sizeof(v));
        std :: memset(laz, 0, sizeof(laz));
        for (int i = 1; i <= n; ++i) {
            int x = read(), y = read(), l = read();
            s[i] = segment(x, y, y + h - 1, l);
            s[i + n] = segment(x + w - 1, y, y + h - 1, -l);
            d[i] = y + h - 1;
            d[i + n] = y;
        }
        
        n <<= 1;
        std :: sort(d + 1, d + 1 + n);
        int dn = std :: unique(d + 1, d + 1 + n) - d - 1;
        std :: sort(s + 1, s + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = std :: lower_bound(d + 1, d + 1 + dn, s[i].y) - d;
            int r = std :: lower_bound(d + 1, d + 1 + dn, s[i].y2) - d;
            modify(1, l, r, s[i].l, 1, dn);
            ans = std :: max(ans, v[1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}