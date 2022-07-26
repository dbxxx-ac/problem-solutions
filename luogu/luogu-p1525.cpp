/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-18 19:27:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-19 01:17:24
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 20005;
const int maxm = 100005;

struct hatred {
    int a, b;
    int num;
}a[maxm];

int fa[maxn], enemy[maxn];

bool cmp(const hatred a, const hatred b) {
    return a.num > b.num;
}

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void unite(int x, int y) {
    int fax = find(x);
    int fay = find(y);
    fa[fax] = fay;
}

bool check(int x, int y) {
    int fax = find(x);
    int fay = find(y);
    return fax == fay;
}

int main() {
    int n, m;
    std :: scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
        std :: scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].num);

    std :: sort(a + 1, a + 1 + m, cmp);
    bool flag = false;

    for (int i = 1; i <= m; ++i) {
        if (check(a[i].a, a[i].b)) {
            std :: printf("%d\n", a[i].num);
            flag = true;
            break;
        }

        if (!enemy[a[i].b]) 
            enemy[a[i].b] = a[i].a;
        else
            unite(a[i].a, enemy[a[i].b]);
        
        if (!enemy[a[i].a])
            enemy[a[i].a] = a[i].b;
        else
            unite(a[i].b, enemy[a[i].a]);
    }

    if (!flag)
        std :: printf("0\n");
    return 0;
}