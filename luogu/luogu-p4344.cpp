/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 05:00:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 05:42:04
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

const int maxn = (int)2e5 + 5;

struct node {
    int len, sum, lmx, rmx, ans;
} t[maxn << 2];

int laz[maxn << 2];

node con(node lef, node rgt) {
    return (node) {
        lef.len + rgt.len,
        lef.sum + rgt.sum,
        std :: max(lef.lmx, (lef.len + rgt.lmx) * (lef.sum == 0)),
        std :: max(rgt.rmx, (rgt.len + lef.rmx) * (rgt.sum == 0)),
        std :: max({lef.ans, rgt.ans, lef.rmx + rgt.lmx})
    };
}

void up(int p) {
    t[p] = con(t[ls(p)], t[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = (node) {
            1, 1, 0, 0, 0
        };
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

void tag(int p, int op) {
    if (op == 1) {
        t[p] = (node) {
            t[p].len, 0, t[p].len, t[p].len, t[p].len
        };
        laz[p] = 1;
    } else {
        t[p] = (node) {
            t[p].len, t[p].len, 0, 0, 0
        };
        laz[p] = 2;
    }
}

void down(int p) {
    if (!laz[p])
        return ;
    tag(ls(p), laz[p]);
    tag(rs(p), laz[p]);
    laz[p] = 0;
}

node query(int p, int l, int r, int L, int R) {
    if (l == L && r == R)
        return t[p];
    down(p);
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

void clear(int p, int l, int r, int L, int R) {
    if (l == L && R == r) {
        tag(p, 1);
        return ;
    }
    down(p);
    int mid = (l + r) >> 1;
    if (R <= mid)
        clear(ls(p), l, mid, L, R);
    else if (L > mid)
        clear(rs(p), mid + 1, r, L, R);
    else {
        clear(ls(p), l, mid, L, mid);
        clear(rs(p), mid + 1, r, mid + 1, R);
    }
    up(p);
}

int sol(int p, int l, int r, int L, int R, int x) {
    if (!x)
        return 0;
    int tot = t[p].len - t[p].sum;
    if (l == L && R == r && tot <= x) {
        tag(p, 2);
        return x - tot;
    }
    down(p);
    int ans = 0, mid = (l + r) >> 1;
    if (R <= mid)
        ans = sol(ls(p), l, mid, L, R, x);
    else if (L > mid)
        ans = sol(rs(p), mid + 1, r, L, R, x);
    else
        ans = sol(rs(p), mid + 1, r, mid + 1, R, 
        sol(ls(p), l, mid, L, mid, x));
    up(p);
    return ans;
}

int main() {
    int n = read(), m = read();
    build(1, 1, n);
    while (m--) {
        int op = read();
        if (op == 0) {
            int l = read(), r = read();
            clear(1, 1, n, l, r);
        } else if (op == 1) {
            int l1 = read(), r1 = read(), l2 = read(), r2 = read();
            int x = query(1, 1, n, l1, r1).sum;
            clear(1, 1, n, l1, r1);
            sol(1, 1, n, l2, r2, x);
        } else {
            int l = read(), r = read();
            printf("%d\n", query(1, 1, n, l, r).ans);
        }
    }
    return 0;
}