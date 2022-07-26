/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-02 20:22:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-02 20:44:31
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 10005;
struct point {
    double x, y;
    const bool operator < (const point &b) {
        return this -> x == b.x ? this -> y < b.y : this -> x < b.x;
    }
}a[maxn];

int update[maxn];

bool cmp_for_update(const int &u, const int &v) {
    return a[u].y < a[v].y;
}

double getdis(int u, int v) {
    return sqrt((a[u].x - a[v].x) * (a[u].x - a[v].x) + (a[u].y - a[v].y) * (a[u].y - a[v].y));
}

double merge(int l, int r) {
    double dis = 1 << 15;
    if (l == r)
        return dis;
    if (l + 1 == r)
        return getdis(l, r);

    int mid = l + r >> 1;
    double disl = merge(l, mid), disr = merge(mid + 1, r);

    dis = std :: min(disl, disr);
    int cnt = 0;
    for (int i = l; i <= r; ++i)
        if (fabs(a[i].x - a[mid].x) <= dis)
            update[++cnt] = i;
    std :: sort(update + 1, update + 1 + cnt, cmp_for_update);
    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt && a[update[j]].y - a[update[i]].y < dis; ++j)
            dis = std :: min(dis, getdis(update[i], update[j]));
    return dis;
}

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lf %lf", &a[i].x, &a[i].y);
    std :: sort(a + 1, a + 1 + n);
    std :: printf("%.4lf\n", merge(1, n));
    return 0;
}