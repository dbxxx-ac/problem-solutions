/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-20 13:20:39 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-20 13:43:56
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

const int maxn = (int)2e5 + 5;
const int maxm = (int)2e5 + 5;

struct node {
    int l, r, ans;
} tr[maxn << 2];

int laz[maxn << 2];

inline node con(node lef, node rgt) {
    node ret;
    ret.l = lef.l;
    ret.r = rgt.r;
    ret.ans = lef.ans + rgt.ans;
    return ret;
}

inline void up(int p) {
    tr[p] = con(tr[ls(p)], tr[rs(p)]);
}

inline void tag(int p) {
    laz[p] ^= 1;
    tr[p].ans = (tr[p].r - tr[p].l + 1 - tr[p].ans);
}

inline void down(int p) {
    if (!laz[p])
        return ;
    tag(ls(p));
    tag(rs(p));
    laz[p] = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        tr[p].l = tr[p].r = l;
        tr[p].ans = rech() ^ '0';
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

void update(int p, int L, int R) {
    int l = tr[p].l, r = tr[p].r;
    if (l == L && r == R)
        return tag(p);
    down(p);
    int mid = (l + r) >> 1;
    if (R <= mid)
        update(ls(p), L, R);
    else if (L > mid)
        update(rs(p), L, R);
    else {
        update(ls(p), L, mid);
        update(rs(p), mid + 1, R);
    }
    up(p);
}

int main() {
    int n = read(), m = read();
    build(1, 1, n);
    while (m--) {
        int op = read(), l = read(), r = read();
        if (op == 0)
            update(1, l, r);
        else
            printf("%d\n", query(1, l, r).ans);
    }
    return 0;
}