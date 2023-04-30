/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-20 13:01:18 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-20 13:16:42
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
inline char rech() {
    char ch = getchar();
    while (!isgraph(ch))
        ch = getchar();
    return ch;
}
inline int ls(int p) {
    return p << 1;
}
inline int rs(int p) {
    return p << 1 | 1;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = (int)2e5 + 5;

struct node {
    int l, r, mx;
} tr[maxn << 2];

inline node con(node lef, node rgt) {
    node ans;
    ans.l = lef.l;
    ans.r = rgt.r;
    ans.mx = std :: max(lef.mx, rgt.mx);
    return ans;
}

inline void up(int p) {
    tr[p] = con(tr[ls(p)], tr[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        tr[p].l = tr[p].r = l;
        tr[p].mx = read();
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

node query(int p, int L, int R) {
    int l = tr[p].l, r = tr[p].r;
    if (l == L && R == r)
        return tr[p];
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

void update(int p, int x, int v) {
    int l = tr[p].l, r = tr[p].r;
    if (l == r) {
        gmx(tr[p].mx, v);
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(ls(p), x, v);
    else
        update(rs(p), x, v);
    up(p);
}

int main() {
    int n = read(), m = read();
    build(1, 1, n);
    while (m--) {
        char op = rech();
        if (op == 'Q') {
            int l = read(), r = read();
            printf("%d\n", query(1, l, r).mx);
        } else {
            int x = read(), v = read();
            update(1, x, v);
        }
    }
    return 0;
}