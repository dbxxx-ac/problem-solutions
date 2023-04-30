/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 01:33:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 02:03:20
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

const int maxn = (int)1e6 + 5;
const int sp = 11451419198LL;

int mx[maxn << 2], asg[maxn << 2], der[maxn << 2];

void up(int p) {
    mx[p] = std :: max(mx[ls(p)], mx[rs(p)]);
}

void build(int p, int l, int r) {
    asg[p] = sp;
    if (l == r) {
        mx[p] = read();
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

void tag(int p, int v, int op) {
    if (op == 1) {
        der[p] = 0;
        asg[p] = v;
        mx[p] = v;
    } else {
        if (asg[p] != sp)
            asg[p] += v;
        else
            der[p] += v;
        mx[p] += v;
    }
}

void down(int p) {
    if (asg[p] != sp) {
        tag(ls(p), asg[p], 1);
        tag(rs(p), asg[p], 1);
        asg[p] = sp;
    } else if (der[p]) {
        tag(ls(p), der[p], 2);
        tag(rs(p), der[p], 2);
        der[p] = 0;
    }
}

void modify(int p, int l, int r, int L, int R, int v, int op) {
    if (l == L && R == r) {
        tag(p, v, op);
        return ;
    }
    down(p);
    int mid = (l + r) >> 1;
    if (R <= mid)
        modify(ls(p), l, mid, L, R, v, op);
    else if (L > mid)
        modify(rs(p), mid + 1, r, L, R, v, op);
    else {
        modify(ls(p), l, mid, L, mid, v, op);
        modify(rs(p), mid + 1, r, mid + 1, R, v, op);
    }
    up(p);
}

int query(int p, int l, int r, int L, int R) {
    if (l == L && R == r)
        return mx[p];
    down(p);
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(ls(p), l, mid, L, R);
    else if (L > mid)
        return query(rs(p), mid + 1, r, L, R);
    else
        return std :: max(
            query(ls(p), l, mid, L, mid),
            query(rs(p), mid + 1, r, mid + 1, R)
        );
}

signed main() {
    int n = read(), q = read();
    build(1, 1, n);
    while (q--) {
        int op = read(), l = read(), r = read();
        if (op <= 2) {
            int v = read();
            modify(1, 1, n, l, r, v, op);
        } else
            printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}