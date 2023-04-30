/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 12:24:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 12:53:10
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

const int maxn = (int)1e4 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int sum, lmx, rmx, ans;
} t[maxn << 2];

inline node con(node lef, node rgt) {
    return (node) {
        lef.sum + rgt.sum,
        std :: max(lef.lmx, lef.sum + rgt.lmx),
        std :: max(rgt.rmx, rgt.sum + lef.rmx),
        std :: max({lef.ans, rgt.ans, lef.rmx + rgt.lmx})
    };
}

inline void up(int p) {
    t[p] = con(t[ls(p)], t[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        int x = read();
        t[p] = (node){x, x, x, x};
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
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
    int T = read();
    while (T--) {
        int n = read();
        build(1, 1, n);
        int m = read();
        while (m--) {
            int l1 = read(), r1 = read(), l2 = read(), r2 = read();
            if (r1 < l2) {
                printf("%d\n",
                    query(1, 1, n, l1, r1).rmx +
                    (r1 + 1 < l2 ? query(1, 1, n, r1 + 1, l2 - 1).sum : 0) +
                    query(1, 1, n, l2, r2).lmx
                );
            } else {
                printf("%d\n", std :: max({
                    query(1, 1, n, l2, r1).ans,
                    l1 == l2 ? -inf : 
                    (query(1, 1, n, l1, l2 - 1).rmx + query(1, 1, n, l2, r2).lmx),
                    r1 == r2 ? -inf :
                    (query(1, 1, n, l1, r1).rmx + query(1, 1, n, r1 + 1, r2).lmx)
                }));
            }
        }
    }
    return 0;
}