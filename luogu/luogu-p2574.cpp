/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-21 23:10:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-22 00:30:19
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
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

const int maxn = 2e5 + 5;
int a[maxn];

long long laz[maxn << 3], val[maxn << 3];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return p << 1 | 1;
}

inline void update(int p) {
    val[p] = val[lson(p)] + val[rson(p)];
}

inline void build(int p, int l, int r) {
    if (l == r) {
        val[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(lson(p), l, mid);
    build(rson(p), mid + 1, r);
    update(p);
}

void pushdown(int p, int l, int r) {
    int len = r - l + 1;
    if (laz[p] == 0)
        return ;
    laz[lson(p)] ^= 1;
    laz[rson(p)] ^= 1;
    val[lson(p)] = len - (len >> 1) - val[lson(p)];
    val[rson(p)] = (len >> 1) - val[rson(p)];
    laz[p] = 0;
}

void modify(int p, int l, int r, int s, int t) {
    pushdown(p, s, t);
    if (l <= s && t <= r) {
        laz[p] ^= 1;
        val[p] = t - s + 1 - val[p];
        return ;
    }
    int mid = s + t >> 1;
    if (l <= mid)
        modify(lson(p), l, r, s, mid);
    if (r > mid)
        modify(rson(p), l, r, mid + 1, t);
    update(p);
}

long long query(int p, int l, int r, int s, int t) {
    if (l <= s && t <= r)
        return val[p];
    pushdown(p, s, t);
    int mid = s + t >> 1;
    long long ans = 0;
    if (l <= mid)
        ans = query(lson(p), l, r, s, mid);
    if (r > mid)
        ans += query(rson(p), l, r, mid + 1, t);
    return ans;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        scanf("%1d", &a[i]);
    build(1, 1, n);
    while (m--) {
        int op = read(), l = read(), r = read();
        if (op == 0)
            modify(1, l, r, 1, n);
        else
            printf("%lld\n", query(1, l, r, 1, n));
    }
    return 0;
}