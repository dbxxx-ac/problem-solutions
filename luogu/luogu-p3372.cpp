/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-03 23:17:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-03 23:25:39
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

const int maxn = (int)1e5 + 5;

struct node {
    int sum, l, r;
} t[maxn << 2];

int laz[maxn << 2];

inline node con(node lef, node rgt) {
    return (node) {
        lef.sum + rgt.sum,
        lef.l,
        rgt.r
    };
}

inline void up(int p) {
    t[p] = con(t[ls(p)], t[rs(p)]);
}

inline void tag(int p, int v) {
    t[p].sum += v * (t[p].r - t[p].l + 1);
    laz[p] += v;
}

inline void down(int p) {
    if (!laz[p])
        return ;
    tag(ls(p), laz[p]);
    tag(rs(p), laz[p]);
    laz[p] = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p].sum = read();
        t[p].l = t[p].r = l;
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

node query(int p, int L, int R) {
    int l = t[p].l, r = t[p].r;
    if (l == L && R == r)
        return t[p];
    down(p);
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(ls(p), L, R);
    else if (L > mid)
        return query(rs(p), L, R);
    else
        return con(
            query(ls(p), L, mid),
            query(rs(p), mid + 1, R)
        );
}

void update(int p, int L, int R, int v) {
    int l = t[p].l, r = t[p].r;
    if (l == L && R == r)
        return tag(p, v);
    down(p);
    int mid = (l + r) >> 1;
    
    if (R <= mid)
        update(ls(p), L, R, v);
    else if (L > mid)
        update(rs(p), L, R, v);
    else {
        update(ls(p), L, mid, v);
        update(rs(p), mid + 1, R, v);
    }

    up(p);
}

signed main() {
    int n = read(), m = read();
    build(1, 1, n);
    
    while (m--) {
        int op = read(), l = read(), r = read();
        if (op == 1) {
            int v = read();
            update(1, l, r, v);
        } else {
            printf("%lld\n", query(1, l, r).sum);
        }
    }

    return 0;
}