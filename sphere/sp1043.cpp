/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 05:50:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 05:52:05
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

const int maxn = (int)5e4 + 5;

struct node {
    int sum, las, ras, ans;
} t[maxn << 2];

inline void up(int p) {
    t[p].sum = t[ls(p)].sum + t[rs(p)].sum;
    t[p].las = std :: max(t[ls(p)].las, t[ls(p)].sum + t[rs(p)].las);
    t[p].ras = std :: max(t[rs(p)].ras, t[rs(p)].sum + t[ls(p)].ras);
    t[p].ans = std :: max({t[ls(p)].ans, t[rs(p)].ans, t[ls(p)].ras + t[rs(p)].las});
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p].sum = t[p].las = t[p].ras = t[p].ans = read();
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

node query(int p, int l, int r, int L, int R) {
    if (l == L && r == R)
        return t[p];
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(ls(p), l, mid, L, R);
    else if (L > mid)
        return query(rs(p), mid + 1, r, L, R);
    else {
        node lef = query(ls(p), l, mid, L, mid);
        node rgt = query(rs(p), mid + 1, r, mid + 1, R);
        return (node) {
            // sum, las, ras, ans
            lef.sum + rgt.sum,
            std :: max(lef.las, lef.sum + rgt.las),
            std :: max(rgt.ras, rgt.sum + lef.ras),
            std :: max({lef.ans, rgt.ans, lef.ras + rgt.las})
        };
    }
}

int main() {
    int n = read();
    build(1, 1, n);
    int m = read();
    while (m--) {
        int l = read(), r = read();
        printf("%d\n", query(1, 1, n, l, r).ans);
    }
    return 0;
}