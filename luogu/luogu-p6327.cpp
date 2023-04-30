/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-03 11:17:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-03 11:56:55
 */
#include <bits/stdc++.h>
#define int long long
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
inline int ls(int p) {
    return p << 1;
}
inline int rs(int p) {
    return p << 1 | 1;
}
const int maxn = (int)2e5 + 5;

double si[maxn << 2], co[maxn << 2];
int der[maxn << 2];

inline void up(int p) {
    si[p] = si[ls(p)] + si[rs(p)];
    co[p] = co[ls(p)] + co[rs(p)];
}

inline void build(int p, int l, int r) {
    if (l == r) {
        int x = read();
        si[p] = sin(x);
        co[p] = cos(x);
        return ;
    }
    
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

inline void update(int p, int v) {
    double s = si[p], c = co[p];
    si[p] = s * cos(v) + c * sin(v);
    co[p] = c * cos(v) - s * sin(v);
}

inline void down(int p) {
    if (!der[p])
        return ;
    update(ls(p), der[p]);
    update(rs(p), der[p]);
    der[ls(p)] += der[p];
    der[rs(p)] += der[p];
    der[p] = 0;
}

double query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R)
        return si[p];
    down(p);
    int mid = (l + r) >> 1;
    double ans = 0;
    if (L <= mid)
        ans = query(ls(p), l, mid, L, R);
    if (R > mid)
        ans += query(rs(p), mid + 1, r, L, R);
    return ans;
}

void add(int p, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        update(p, v);
        der[p] += v;
        return ;
    }
    down(p);
    int mid = (l + r) >> 1;
    if (L <= mid)
        add(ls(p), l, mid, L, R, v);
    if (R > mid)
        add(rs(p), mid + 1, r, L, R, v);
    up(p);
}

signed main() {
    int n = read();
    build(1, 1, n);
    int m = read();
    while (m--) {
        int op = read(), l = read(), r = read();
        if (op == 1) {
            int v = read();
            add(1, 1, n, l, r, v);
        } else {
            printf("%.1f\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}