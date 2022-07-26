/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-26 11:08:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-11 13:03:56
 */
#include <bits/stdc++.h>
inline long long read() {
    long long x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}

long long mod;
const int maxn = 100005;
long long a[maxn], val[maxn << 2], mul[maxn << 2], sum[maxn << 2];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return (p << 1) | 1;
}

inline void update(int p) {
    val[p] = (val[lson(p)] + val[rson(p)]) % mod;
}

void build(int l, int r, int p) {
    mul[p] = 1;
    sum[p] = 0;
    if (l == r) {
        val[p] = a[l] % mod;
        return ;
    }
    int mid = l + r >> 1;
    build(l, mid, lson(p));
    build(mid + 1, r, rson(p));
    update(p);
    return ;
}

void pushdown(int l, int r, int p) {
    int mid = l + r >> 1, s = lson(p), t = rson(p);
    val[s] = (val[s] * mul[p] + sum[p] * (mid - l + 1)) % mod;
    val[t] = (val[t] * mul[p] + sum[p] * (r - mid)) % mod;
    sum[s] = (sum[s] * mul[p] + sum[p]) % mod;
    sum[t] = (sum[t] * mul[p] + sum[p]) % mod;
    mul[s] = (mul[s] * mul[p]) % mod;
    mul[t] = (mul[t] * mul[p]) % mod;
    mul[p] = 1;
    sum[p] = 0;
    return ;
}

void add(int l, int r, long long v, int s, int t, int p) {
    int mid = s + t >> 1;
    if (l <= s && t <= r) {
        val[p] += v * (t - s + 1);
        val[p] %= mod;
        sum[p] += v;
        sum[p] %= mod;
        return ;
    }
    pushdown(s, t, p);
    if (l <= mid)
        add(l, r, v, s, mid, lson(p));
    if (r > mid)
        add(l, r, v, mid + 1, t, rson(p));
    update(p);
    return ;
}

void multi(int l, int r, long long v, int s, int t, int p) {
    int mid = s + t >> 1;
    if (l <= s && t <= r) {
        mul[p] *= v;
        mul[p] %= mod;
        sum[p] *= v;
        sum[p] %= mod;
        val[p] *= v;
        val[p] %= mod;
        return ;
    }
    pushdown(s, t, p);
    if (l <= mid)
        multi(l, r, v, s, mid, lson(p));
    if (r > mid)
        multi(l, r, v, mid + 1, t, rson(p));
    update(p);
    return ;
}

long long getval(int l, int r, int s, int t, int p) {
    int mid = s + t >> 1;
    long long ans = 0;
    if (l <= s && t <= r)
        return val[p];
    pushdown(s, t, p);
    if (l <= mid)
        ans = getval(l, r, s, mid, lson(p)) % mod;
    if (r > mid)
        ans += getval(l, r, mid + 1, t, rson(p)) % mod;
    return ans % mod;
}

int main() {
    int n = read(), m = read();
    mod = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(1, n, 1);
    while (m--) {
        int op = read();
        if (op == 1) {
            int x = read(), y = read();
            long long k = read();
            multi(x, y, k, 1, n, 1);
        } else if (op == 2) {
            int x = read(), y = read();
            long long k = read();
            add(x, y, k, 1, n, 1);
        } else if (op == 3) {
            int x = read(), y = read();
            printf("%lld\n", getval(x, y, 1, n, 1));
        }
    }
    return 0;
}