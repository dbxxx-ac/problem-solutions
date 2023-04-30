/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-03 07:21:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-03 08:30:20
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

const int maxn = (int)1e5 + 5;
const int mod = 571373;
int sum[maxn << 2], der[maxn << 2], mul[maxn << 2];

inline int ls(int p) {
    return p << 1;
}
inline int rs(int p) {
    return p << 1 | 1;
}

inline void up(int p) {
    sum[p] = (sum[ls(p)] + sum[rs(p)]) % mod;
}

void build(int p, int l, int r) {
    mul[p] = 1;
    if (l == r) {
        sum[p] = read();
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    up(p);
}

inline void down(int p, int l, int r) {
    if (mul[p] != 1) {
        (mul[ls(p)] *= mul[p]) %= mod;
        (der[ls(p)] *= mul[p]) %= mod;
        (sum[ls(p)] *= mul[p]) %= mod; 
        (mul[rs(p)] *= mul[p]) %= mod;
        (der[rs(p)] *= mul[p]) %= mod;
        (sum[rs(p)] *= mul[p]) %= mod;
        mul[p] = 1;
    }
    if (der[p]) {
        int mid = (l + r) >> 1;
        (der[ls(p)] += der[p]) %= mod;
        (sum[ls(p)] += der[p] * (mid - l + 1)) %= mod;
        (der[rs(p)] += der[p]) %= mod;
        (sum[rs(p)] += der[p] * (r - mid)) %= mod;
        der[p] = 0;
    }
}

void add(int p, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        (der[p] += v) %= mod;
        (sum[p] += v * (r - l + 1)) %= mod;
        return ;
    }
    down(p, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid)
        add(ls(p), l, mid, L, R, v);
    if (R > mid)
        add(rs(p), mid + 1, r, L, R, v);
    up(p);
}

void multi(int p, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        (mul[p] *= v) %= mod;
        (der[p] *= v) %= mod;
        (sum[p] *= v) %= mod;
        return ;
    }
    down(p, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid)
        multi(ls(p), l, mid, L, R, v);
    if (R > mid)
        multi(rs(p), mid + 1, r, L, R, v);
    up(p);
}

int query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R)
        return sum[p];
    down(p, l, r);
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid)
        ans = query(ls(p), l, mid, L, R);
    if (R > mid)
        ans += query(rs(p), mid + 1, r, L, R);
    return ans % mod;
}

signed main() {
    int n = read(), m = read(); read();
    build(1, 1, n);
    while (m--) {
        int op = read(), l = read(), r = read();
        if (op == 1) {
            int v = read();
            multi(1, 1, n, l, r, v);
        } else if (op == 2) {
            int v = read();
            add(1, 1, n, l, r, v);
        } else {
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}