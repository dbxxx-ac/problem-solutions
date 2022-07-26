/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-21 22:07:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-21 22:50:54
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

const int maxn = 1e5 + 5;
int n, m, val[maxn << 2];
double sl[maxn << 2];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return p << 1 | 1;
}

inline void update(int p) {
    sl[p] = std :: max(sl[lson(p)], sl[rson(p)]);
}

int query(int p, int l, int r, double s) {
    if (sl[p] <= s)
        return 0;
    if (l == r)
        return 1;
    int mid = l + r >> 1;
    if (sl[lson(p)] > s)
        return query(lson(p), l, mid, s) + val[p] - val[lson(p)];
    return query(rson(p), mid + 1, r, s);
}

void modify(int p, int s, int t, double v, int k) {
    if (s == k && t == k) {
        val[p] = 1;
        sl[p] = v;
        return ;
    }
    int mid = s + t >> 1;
    if (k <= mid)
        modify(lson(p), s, mid, v, k);
    else
        modify(rson(p), mid + 1, t, v, k);
    update(p);
    val[p] = val[lson(p)] + query(rson(p), mid + 1, t, sl[lson(p)]);
}

int main() {
    int n = read(), m = read();
    while (m--) {
        int x = read(), y = read();
        modify(1, 1, n, (double)y / x, x);
        printf("%d\n", val[1]);
    }
    return 0;
}