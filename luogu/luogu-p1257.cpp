/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-15 17:38:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-15 18:16:46
 */
#include <bits/stdc++.h>

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

const int maxn = 10005;
const int inf = 0x3f3f3f3f;

struct node {
    double x, y;
}a[maxn];

inline double min(double a, double b) {
    return a < b ? a : b;
}

inline double fabs(double x) {
    return x > 0 ? x : -x;
}

int ner[maxn];

inline double dis(int p, int q) {
    return hypot(a[p].x - a[q].x, a[p].y - a[q].y);
}

double merge(int l, int r) {
    if (l == r)
        return inf;
    if (l + 1 == r)
        return dis(l, r);
    
    int mid = (l + r) >> 1;
    double d = min(merge(l, mid), merge(mid + 1, r));

    int cnt = 0;
    for (int i = l; i <= r; ++i)
        if (fabs(a[mid].x - a[i].x) < d)
            ner[++cnt] = i;
    
    std :: sort(ner + 1, ner + 1 + cnt, [](int x, int y) {
        return a[x].y < a[y].y;
    });

    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt && a[ner[j]].y - a[ner[i]].y < d; ++j) {
            d = min(d, dis(ner[i], ner[j]));
        }
    
    return d;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }

    std :: sort(a + 1, a + 1 + n, [](node x, node y) {
        return x.x < y.x;
    });

    printf("%.4f\n", merge(1, n));
    return 0;
}