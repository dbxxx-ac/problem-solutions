/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-10 08:59:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-10 12:21:19
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
inline int lowbit(int x) {
    return x & (-x);
}
inline int ls(int p) {
    return p << 1;
}
inline int rs(int p) {
    return p << 1 | 1;
}

const int maxn = (int)1e6 + 5;

int t[maxn];

int n;

inline void del(int x) {
    for (; x <= n; x += lowbit(x))
        --t[x];
}

inline int kth(int k) {
    int sum = 0, x = 0;
    for (int i = 21; ~i; --i) {
        x += 1 << i;
        if (x >= n || sum + t[x] >= k)
            x -= 1 << i;
        else
            sum += t[x];
    }
    return x + 1;
}

struct node {
    int mx, mn;
} tr[maxn << 2];

inline node con(node l, node r) {
    return (node) {
        std :: max(l.mx, r.mx),
        std :: min(l.mn, r.mn)
    };
}

inline void up(int p) {
    tr[p] = con(tr[ls(p)], tr[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        int x = read();
        tr[p] = (node){x, x};
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
    return ;
}

node query(int p, int l, int r, int L, int R) {
    if (l == L && R == r)
        return tr[p];
    
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

void update(int p, int l, int r, int x) {
    if (l == r) {
        tr[p] = (node){-0x3f3f3f3f, 0x3f3f3f3f};
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(ls(p), l, mid, x);
    else
        update(rs(p), mid + 1, r, x);
    up(p);
    return ;
}

int main() {
    n = read();
    int m = read();
    for (int i = 1; i <= n; ++i)
        t[i] = lowbit(i);
    build(1, 1, n);

    while (m--) {
        int op = read();
        if (op == 1) {
            int x = kth(read());
            update(1, 1, n, x);
            del(x);
        } else {
            int l = kth(read()), r = kth(read());
            node ans = query(1, 1, n, l, r);
            printf("%d %d\n", ans.mn, ans.mx);
        }
    }

    return 0;
}