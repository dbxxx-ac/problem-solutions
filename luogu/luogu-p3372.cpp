/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-26 10:35:03 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-26 11:14:11
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

const int maxn = 100005;
int n;
long long a[maxn], d[maxn << 2], laz[maxn << 2];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return (p << 1) | 1;
}

void build(int l, int r, int p) {
    if (l == r) {
        d[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(l, mid, lson(p));
    build(mid + 1, r, rson(p));
    d[p] = d[lson(p)] + d[rson(p)];
    return ;
}

void update(int l, int r, int v, int s, int t, int p) {
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * v;
        laz[p] += v;
        return ;
    }
    int mid = s + t >> 1;
    if (laz[p]) {
        d[lson(p)] += laz[p] * (mid - s + 1);
        d[rson(p)] += laz[p] * (t - mid);
        laz[lson(p)] += laz[p];
        laz[rson(p)] += laz[p];
        laz[p] = 0;
    }
    if (l <= mid)
        update(l, r, v, s, mid, lson(p));
    if (r > mid)
        update(l, r, v, mid + 1, t, rson(p));
    d[p] = d[lson(p)] + d[rson(p)];
}

long long getsum(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r)
        return d[p];
    int mid = s + t >> 1;
    if (laz[p]) {
        d[lson(p)] += laz[p] * (mid - s + 1);
        d[rson(p)] += laz[p] * (t - mid);
        laz[lson(p)] += laz[p];
        laz[rson(p)] += laz[p];
        laz[p] = 0;
    }
    long long sum = 0;
    if (l <= mid)
        sum = getsum(l, r, s, mid, lson(p));
    if (r > mid)
        sum += getsum(l, r, mid + 1, t, rson(p));
    return sum;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(1, n, 1);
    while (m--) {
        int op = read();
        if (op == 1) {
            int x = read(), y = read(), k = read();
            update(x, y, k, 1, n, 1);
        } else if (op == 2) {
            int x = read(), y = read();
            printf("%lld\n", getsum(x, y, 1, n, 1));
        }
    }
    return 0;
}