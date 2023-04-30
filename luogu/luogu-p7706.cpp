/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 00:44:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 01:09:43
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
inline int ls(int p) {
    return p << 1;
}
inline int rs(int p) {
    return p << 1 | 1;
}

const int maxn = (int)5e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int amx, bmn, led, rgd, ans;
} t[maxn << 2];

int a[maxn];

node con(node le, node rg) {
    return (node) {
        std :: max(le.amx, rg.amx),
        std :: min(le.bmn, rg.bmn),
        std :: max({le.led, rg.led, le.amx - rg.bmn}),
        std :: max({le.rgd, rg.rgd, rg.amx - le.bmn}),
        std :: max({le.ans, rg.ans, le.led + rg.amx, le.amx + rg.rgd})
    };
}

void up(int p) {
    t[p] = con(t[ls(p)], t[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = (node) {
            a[l], read(), -inf, -inf, -inf
        };
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

void update(int p, int l, int r, int x, int v, int ty) {
    if (l == r) {
        if (ty == 1)
            t[p].amx = v;
        else
            t[p].bmn = v;
        return ;
    }

    int mid = (l + r) >> 1;
    if (x <= mid)
        update(ls(p), l, mid, x, v, ty);
    else
        update(rs(p), mid + 1, r, x, v, ty);
    up(p);
}

node query(int p, int l, int r, int L, int R) {
    if (l == L && R == r)
        return t[p];
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(ls(p), l, mid, L, R);
    else if (L > mid)
        return query(rs(p), mid + 1, r, L, R);
    else
        return con(
            query(ls(p), l, mid, L, mid),
            query(rs(p), mid + 1, r, mid + 1, R)
        );
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(1, 1, n);
    while (m--) {
        int op = read();
        if (op <= 2) {
            int x = read(), v = read();
            update(1, 1, n, x, v, op);
        } else {
            int l = read(), r = read();
            printf("%d\n", query(1, 1, n, l, r).ans);
        }
    }
    return 0;
}