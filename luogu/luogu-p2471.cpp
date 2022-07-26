/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-17 22:11:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-17 22:23:57
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

const int maxn = 50005;
int v[maxn << 2], b[maxn], a[maxn]; // y -> b, r -> a

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return p << 1 | 1;
}

inline void update(int p) {
    v[p] = std :: max(v[lson(p)], v[rson(p)]);
}

void build(int l, int r, int p) {
    if (l == r) {
        v[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(l, mid, lson(p));
    build(mid + 1, r, rson(p));
    update(p);
}

int getval(int l, int r, int s, int t, int p) {
    if (s == l && t == r)
        return v[p] ;
    int mid = s + t >> 1;
    if (r <= mid)
        return getval(l, r, s, mid, lson(p));
    else if (l > mid)
        return getval(l, r, mid + 1, t, rson(p));
    else
        return std :: max(getval(l, mid, s, mid, lson(p)), getval(mid + 1, r, mid + 1, t, rson(p)));
    return 114514;
}

int bfind(int x, int n) {
    int l = 1, r = n, mid = l + r >> 1;
    while (l <= r) {
        if (b[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
        mid = l + r >> 1;
    }
    return l;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        b[i] = read();
        a[i] = read();
    }
    
    build(1, n, 1);

    int m = read();
    while (m--) {
        int x = read(), y = read(); // x -> y, y -> x
        if (x >= y) {
            puts("false");
            continue;
        }
        
        int u = bfind(x, n);
        int v = bfind(y, n);
        if (u != n + 1 && x == b[u]) {
            if (v != n + 1 && y == b[v]) {
                if (a[u] < a[v]) {
                    puts("false");
                    continue;
                }

                if (v == u + 1) {
                    if (y == x + 1)
                        puts("true");
                    else
                        puts("maybe");
                    continue;
                }

                int pmax = getval(u + 1, v - 1, 1, n, 1);
                if (pmax >= a[v])
                    puts("false");
                else if (y - x == v - u)
                    puts("true");
                else
                    puts("maybe");
            } else {
                if (v == u + 1) {
                    puts("maybe");
                    continue;
                }
                
                int pmax = getval(u + 1, v - 1, 1, n, 1);
                if (pmax >= a[u])
                    puts("false");
                else
                    puts("maybe");
            }
        } else {
            if (v != n + 1 && y == b[v]) {
                if (u == v) {
                    puts("maybe");
                    continue;
                }
                
                int pmax = getval(u, v - 1, 1, n, 1);
                if (pmax >= a[v])
                    puts("false");
                else
                    puts("maybe");
            } else {
                puts("maybe");
            }
        }
    }
    return 0;
}