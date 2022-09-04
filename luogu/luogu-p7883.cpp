/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-15 17:38:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-15 18:08:42
 */
#include <bits/stdc++.h>

#define int long long

inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 400005;
const int inf = LONG_LONG_MAX;

struct node {
    int x, y;
}a[maxn];

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int sq(int x) {
    return x * x;
}

int ner[maxn];

inline int dis2(int p, int q) {
    return sq(a[p].x - a[q].x) + sq(a[p].y - a[q].y);
}

int merge(int l, int r) {
    if (l == r)
        return inf;
    if (l + 1 == r)
        return dis2(l, r);
    
    int mid = (l + r) >> 1;
    int d = min(merge(l, mid), merge(mid + 1, r));

    int cnt = 0;
    for (int i = l; i <= r; ++i)
        if (sq(a[mid].x - a[i].x) < d)
            ner[++cnt] = i;
    
    std :: sort(ner + 1, ner + 1 + cnt, [](int x, int y) {
        return a[x].y < a[y].y;
    });

    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt && sq(a[ner[j]].y - a[ner[i]].y) < d; ++j) {
            d = min(d, dis2(ner[i], ner[j]));
        }
    
    return d;
}

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].x = read();
        a[i].y = read();
    }

    std :: sort(a + 1, a + 1 + n, [](node x, node y) {
        return x.x < y.x;
    });

    printf("%lld\n", merge(1, n));
    return 0;
}